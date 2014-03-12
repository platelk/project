/*
** detect_param.c for detect_param in /home/desoul_b//rush/rush1
** 
** Made by benoit desoulle
** Login   <desoul_b@epitech.net>
** 
** Started on  Fri Nov 25 21:20:20 2011 benoit desoulle
** Last update Sun Nov 27 13:33:46 2011 kevin platel
*/

#include <stdlib.h>
#include <string.h>
#include "my.h"
#include "marvin.h"

void    aff_type(char *str)
{
  if (strncmp(str, "struct", 6) == 0)
    my_printf("structure de type ");
  else if (strncmp(str, "int", 3) == 0)
    my_printf("entier ");
  else if (strncmp(str, "char", 4) == 0)
    my_printf("charactere ");
  else if (strncmp(str, "long", 4) == 0)
    my_printf("long ");
  else if (strncmp(str, "short", 5) == 0)
    my_printf("court ");
  else if (strncmp(str, "void", 4) == 0)
    my_printf("rien ");
  else if (strncmp(str, "float", 5) == 0)
    my_printf("nombre flottant ");
  else if (strncmp(str, "double", 6) == 0)
    my_printf("nombre flottant ");
  else if (strncmp(str, "static", 6) == 0);
  else if (strcmp(str, "const") == 0);
  else if (strcmp(str, "unsigned") == 0);
  else
    my_printf("%s ", str);
}

int	detect_tab(char *str)
{
  int	i;
  int	detec;

  if (str[0] == ')')
    {
      my_printf("rien");
      return (1);
    }
  i = -1;
  detec = 0;
  while (str[++i] != '\0')
    if (str[i] == '*')
      detec += my_printf(" pointeur sur ");
  i = -1;
  while (str[++i] != '\0' && str[i] != 'v');
  if (detec == 0 && (strncmp(str, "void", 4) == 0))
    {
      my_printf("\n Erreur, type void ne peut pas être assignié !\n");
      exit (1);
    }
  i = -1;
  while (str[++i] != '\0')
    if (str[i] == '[')
      my_printf("tableau de ");
  return (detec);
}

void	find_const(char **str)
{
  int	i;

  i = -1;
  while (str[++i] != '\0')
      if (strcmp(str[i], "const") == 0)
	my_printf("constant ");
  i = -1;
  while (str[++i] != '\0')
      if (strcmp(str[i], "unsigned") == 0)
	my_printf("non signé ");
  i = -1;
  while (str[++i] != '\0')
      if (strcmp(str[i], "static") == 0)
	my_printf("statique ");
}

int	type(char *str)
{
  int	i;
  char	**str2;

  if (str == NULL)
    exit(0);
  my_printf("un ");
  i = -1;
  str2 = my_new_str_to_wordtab(str);
  if (str2[0] == '\0' || detect_tab(str) == 1)
    return (0);
  while (str2[++i] != '\0');
  if (i == 1)
    aff_type(str2[0]);
  else
    {
      i = -1;
      while (str2[(++i) + 1] != '\0')
	aff_type(str2[i]);
      find_const(str2);
      if (my_strcmp(str2[i - 1], "struct") == 0)
	my_printf("%s ", str2[i]);
      else
	my_printf("nommé %s ", my_new_str_to_wordtab(str2[i])[0]);
    }
  return (0);
}
