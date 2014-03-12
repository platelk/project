/*
** config_prompt.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 12:35:04 2012 alexis leprovost
** Last update Sat May 19 21:33:46 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"global.h"
#include	"config.h"
#include	"my.h"
#include	"my_strtok.h"
#include	"xsys.h"

static int	escape_char(char c)
{
  if (c == 'a')
    return ('\a');
  else if (c == 'b')
    return ('\b');
  else if (c == 't')
    return ('\t');
  else if (c == 'n')
    return ('\n');
  else if (c == 'v')
    return ('\v');
  else if (c == 'f')
    return ('\f');
  else if (c == 'r')
    return ('\r');
  else
    return (c);
}

static int	magic_number(char *str)
{
  int	nb;
  int	i;

  nb = 0;
  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] && (str[i] >= '0' && str[i] <= '7'))
    nb = (nb * 8) + (str[i++] - 48);
  return (nb);
}

static int	check_quote(int match)
{
  if ((match % 2) == 1)
    {
      fprintf(stderr, "Unmatched \".\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

static int	fill_prompt(char *prompt, char *str)
{
  int	i;
  int	k;
  int	match;

  i = -1;
  k = -1;
  match = 0;
  if (str == NULL || prompt == NULL)
    return (EXIT_FAILURE);
  while (str[++k] && match < 2)
    {
      if (str[k] == '\\' && (str[k + 1] >= '0' && str[k + 1] <= '7'))
	{
	  prompt[++i] = magic_number(&str[k + 1]);
	  while (str[k] && (str[k + 1] >= '0' && str[k + 1] <= '7'))
	    ++k;
	}
      else if (str[k] == '\\' && str[k + 1] != '\0')
	prompt[++i] = escape_char(str[++k]);
      else if (str[k] != PROMPT_CHAR)
	prompt[++i] = str[k];
      else
	++match;
    }
  return (check_quote(match));
}

int	config_prompt(char *str, t_config *config)
{
  char	**tab;
  char	*base;
  char	*prompt;

  base = DELIM_PROMPT_STRING;
  if (str == NULL || config == NULL)
    return (EXIT_FAILURE);
  prompt = NULL;
  if ((tab = my_strtok(str, base, TOK_DELIM)) == NULL ||
      my_tablen(tab) != PROMPT_STRING_NUMBER ||
      (prompt = xmalloc(sizeof(*prompt) * (my_strlen(tab[1]) + 1))) == NULL ||
      fill_prompt(prompt, tab[1]) == EXIT_FAILURE)
    {
      (tab) ? my_free_tab(tab) : (tab = NULL);
      (prompt) ? free(prompt) : (prompt = NULL);
      return (EXIT_FAILURE);
    }
  if (config->prompt != NULL)
    free(config->prompt);
  my_free_tab(tab);
  config->prompt = prompt;
  return (EXIT_SUCCESS);
}
