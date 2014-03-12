/*
** Epitech Security Lab
** http://esl.epitech.net - <staff@esl.epitech.eu>
**
** Zerk and Djo wrote this.
** As long as you retain this notice you can do whatever
** you want with this stuff. If we meet some day, and you
** think this stuff is worth it, you can buy us some belgian
** beers in return.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "pepito.h"
#include "network.h"
#include "daemon.h"
#include "utils.h"
#include "recipes.h"
#include "secret.h"

static char		adminPassword[512] = "\x25\x20\x21\x34\x3c\x3b\x38\x3a\x3b\x05\x05\x16"; /* putainmonPPC */
static char		userPassword[512] = "jt3d1l4t3";
static char    		xorKey = 0x55;
static int    		money = 0;

t_recipes               tab_recipes[] =
{
  {"Granola with some MDMA", 0},
  {"Granola with some Whisky", 0},
  {"Granola with some Cum", 0},
  {"Granola with some LSD", 0},
  {"Secret Granola", 0},
  {NULL, 0}
};

t_stock                 stock[] =
{
  {"MDMA",       10},
  {"Whisky",     10},
  {"Cum",        10},
  {"LSD",        10},
  {"Chocolate",  10},
  {"Flour",      10},
  {NULL,         0}
};

/* --- checkPassword() ---------------------------------------------- */

int
checkPassword(char *password)
{
  char			savePassword[64] = {0};
  char			*logMessage;
  int			isUser = 0;
  int			isAdmin = 0;
  int			i;

  if (!strcmp(password, userPassword))
    isUser = 1;
  strcpy(savePassword, password);

  for (i = 0; password[i]; ++i)
    password[i] ^= xorKey;
  if (!strcmp(password, adminPassword))
    isAdmin = 1;

  if (!(isAdmin | isUser)) {
    logMessage = malloc(sizeof(*logMessage) * (strlen(password) + 21));
    memset(logMessage, 0, strlen(password) + 21);
    strcat(logMessage, "Invalid password : ");
    strcat(logMessage, savePassword);
    strcat(logMessage, "\n");
    sendLogMessage(logMessage);
    free(logMessage);
  }
  return isAdmin ? ADMIN : isUser ? USER : NOBODY;
}

/* --- change*Password() -------------------------------------------- */

static void
changeUserPassword(char *password)
{
  if (password) {
    strcpy(userPassword, password);
    sendLogMessage(PASSWD_CHANGE);
  }
}

static void
changeAdminPassword(char *password)
{
  int			i;

  if (password) {
    for (i = 0; password[i]; ++i)
      password[i] ^= xorKey;
    strcpy(adminPassword, password);
    sendLogMessage(PASSWD_CHANGE);
  }
}

/* --- Packet handlers ---------------------------------------------- */

static int
handlerChangePassword(void *packetPtr, size_t packetSize)
{
  int			identity = NOBODY;
  char			*newPassword;
  char			*oldPassword;

  oldPassword = getStr(&packetPtr, &packetSize);
  newPassword = getStr(&packetPtr, &packetSize);
  if ((identity = checkPassword(oldPassword)) == ADMIN)
    changeAdminPassword(newPassword);
  else if (identity == USER)
    changeUserPassword(newPassword);
  if (newPassword)
    free(newPassword);
  if (oldPassword)
    free(oldPassword);
  return 0;
}

/* --- Display all Recipes ------------------------------------------ */

static int
handlerDisplayRecipes(void *packetPtr, size_t packetSize)
{
  int			i;
  int			user = NOBODY;
  char			msg[256] = {0};
  char			*password = NULL;

  password = getStr(&packetPtr, &packetSize);
  user = checkPassword(password);
  if (user == USER || user == ADMIN) {
    sendLogMessage("Lists of Recipes\n================\n");
    for (i = 0; tab_recipes[i].name; ++i) {
      snprintf(msg, sizeof(msg), "[%d] - %s\n", i, tab_recipes[i].name);
      sendLogMessage(msg);
    }
  }
  free(password);
  return 0;
}

/* --- Display Stock of Granola Corp --------------------------------- */

static int
handlerDisplayStock(void *packetPtr, size_t packetSize)
{
  int			i;
  int			user = NOBODY;
  char			msg[256] = {0};
  char			*password = NULL;

  password = getStr(&packetPtr, &packetSize);
  if ((user = checkPassword(password)) == USER || user == ADMIN) {
    snprintf(msg, sizeof(msg), "Money : %d\n", money);
    sendLogMessage(msg);
    sendLogMessage("\nIngredient stock\n================\n");
    for (i = 0; stock[i].name; ++i) {
      snprintf(msg, sizeof(msg), "[%d] - %s\n", stock[i].quantity, stock[i].name);
      sendLogMessage(msg);
    }
    sendLogMessage("\nFor sale\n========\n");
    for (i = 0; tab_recipes[i].name; ++i) {
      if (tab_recipes[i].quantity) {
	snprintf(msg, sizeof(msg), "%d x %s\n", tab_recipes[i].quantity, tab_recipes[i].name);
	sendLogMessage(msg);
      }
    }
  }
  free(password);
  return 0;
}

/* --- Make Recipes -------------------------------------------------- */

static int
_checkIngredient(unsigned int id)
{
  if (id > sizeof(stock) / sizeof(t_stock))
    return -1;
  return 0;
}

static char *
_checkStock(int id)
{
  if (stock[CHOCOLATE].quantity - 1 < 0)
    return "Need more Chocolate";
  if (stock[FLOUR].quantity - 1 < 0)
    return "Need more Flour";
  if (id == MDMA && stock[MDMA].quantity - 1 < 0)
    return "Need more MDMA";
  if (id == WHISKY && stock[WHISKY].quantity - 1 < 0)
    return "Need more WHISKY";
  if (id == CUM && stock[CUM].quantity - 1 < 0)
    return "Need more CUM";
  if (id == LSD && stock[LSD].quantity - 1 < 0)
    return "Need more LSD";
  return NULL;
}

static void
_useIngredient(int MagicIngredient)
{
  stock[CHOCOLATE].quantity		-= 1;
  stock[FLOUR].quantity			-= 1;
  stock[MagicIngredient].quantity	-= 1;
  tab_recipes[MagicIngredient].quantity += 1;
}

static int
handlerMakeRecipes(void *packetPtr, size_t packetSize)
{
  int			id = 0;
  char			*recipe;
  char			*log;
  char			msg[256];
  char			*password = NULL;

  password = getStr(&packetPtr, &packetSize);
  if (checkPassword(password) == ADMIN) {
    recipe = getStr(&packetPtr, &packetSize);
    if ((log = _checkStock(id))) {
      sendLogMessage(log);
      return -1;
    }
    fprintf(stderr, "Recipe : '%s'\n", recipe);
    for (id = 0; tab_recipes[id].name != NULL
	   && strcmp(tab_recipes[id].name, recipe); ++id);
    if (tab_recipes[id].name == NULL) {
      sendLogMessage(UNKNOWN_RECIPE);
      return -1;
    }

    if (_checkIngredient(id)) {
      sendLogMessage(UNKNOWN_INGREDIENT);
      return -1;
    }
    _useIngredient(id);
    snprintf(msg, sizeof(msg), "%s was made\n", tab_recipes[id].name);
    sendLogMessage(msg);
    free(recipe);
  }
  free(password);
  return 0;
}

/* --- Sale Granola ----------------------------------------------- */

static int
handlerSaleGranola(void *packetPtr, size_t packetSize)
{
  char			*recipe;
  int			user = NOBODY;
  int			id;
  char			msg[256];
  char			*password = NULL;

  password = getStr(&packetPtr, &packetSize);
  if ((user = checkPassword(password)) == USER || user == ADMIN) {
    recipe = getStr(&packetPtr, &packetSize);
    for (id = 0; tab_recipes[id].name != NULL
	   && strcmp(tab_recipes[id].name, recipe); ++id) ;
    if (tab_recipes[id].name == NULL) {
      sendLogMessage(UNKNOWN_RECIPE);
      return -1;
    }
    if (tab_recipes[id].quantity > 0) {
      tab_recipes[id].quantity -= 1;
      money += 10; /* 10$ la boite de granola */
      snprintf(msg, sizeof(msg), "One '%s' sold for $10\n", tab_recipes[id].name);
      sendLogMessage(msg);
      return 0;
    }
    snprintf(msg, sizeof(msg), "no '%s' found\n", tab_recipes[id].name);
    sendLogMessage(msg);
    free(recipe);
  }
  free(password);
  return -1;
}

static int
handlerBuyIngredient(void *packetPtr, size_t packetSize)
{
  int			i;
  char			*ingredientName;
  int			amount;
  char			log[128];
  char			*password = NULL;

  password = getStr(&packetPtr, &packetSize);
  if (checkPassword(password) == ADMIN) {
    ingredientName = getStr(&packetPtr, &packetSize);
    amount = getNumber(&packetPtr, &packetSize);

    if ((money - 2 * amount) < 0) {
      sendLogMessage("Need more money !!\n");
      return -1;
    }

    for (i = 0; stock[i].name != NULL; ++i) {
      if (!strcmp(ingredientName, stock[i].name)) {
	money -= 2 * amount;
	stock[i].quantity += amount;
	sendLogMessage(INGREDIENT_BOUGHT);
	sprintf(log, "echo \"%s was bought\" >> log", ingredientName);
	free(ingredientName);
	system(log);
	return amount;
      }
    }

    sendLogMessage(UNKNOWN_INGREDIENT);
  }
  return -1;
}

/* --- Handler function -------------------------------------------- */

static int		(*handlerTab[])(void *packetPtr, size_t packetSize) =
{
  handlerChangePassword,
  handlerDisplayRecipes,
  handlerDisplayStock,
  handlerMakeRecipes,
  handlerMakeSecretRecipes,
  handlerSaleGranola,
  handlerBuyIngredient,
  NULL
};

#define HANDLER_LEN (sizeof(handlerTab) / sizeof (handlerTab[0]))

/* --- handlePacket() ----------------------------------------------- */

int
handlePacket(void *packetPtr, size_t packetSize)
{
  int			cmdId;

  cmdId = getNumber(&packetPtr, &packetSize);
  if (cmdId > (int)HANDLER_LEN)
    fprintf(stderr, "ID (%i) out of range.\n", cmdId);
  else
    handlerTab[cmdId](packetPtr, packetSize);
  return 0;
}

/* --- main() ------------------------------------------------------- */

int
main(int argc, char **argv)
{
  if (argc > 1) {
    if (!strcmp(argv[1], "start"))
      return (runDaemon(0));
    else if (!strcmp(argv[1], "debug"))
      return (runDaemon(1));
    else if (!strcmp(argv[1], "stop"))
      return (stopDaemon());
  }
  fprintf(stderr, "usage: %s {start|debug|stop}\n", argv[0]);
  return EXIT_SUCCESS;
}
