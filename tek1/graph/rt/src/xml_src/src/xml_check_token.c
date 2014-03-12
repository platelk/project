/*
** xml_check_token.c for xml in /home/vink/projet/graph/rt/src/xml_src/src
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:23:08 2012 kevin platel
** Last update Sun Jun  3 16:23:10 2012 kevin platel
*/

#include	<stdlib.h>

#include	"my.h"
#include	"my_strtok.h"
#include	"xml_token.h"
#include	"xml_error.h"

int	xml_check_presence(char *s, char *check, char *base)
{
  char	**tab;
  int	i;

  tab = my_strtok(s, base, TOK_BASE);
  if (!tab)
    return (EXIT_FAILURE);
  i = 0;
  while (tab[i])
    {
      if (my_strcmp(check, tab[i]) == 0)
	return (EXIT_SUCCESS);
      i++;
    }
  return (EXIT_FAILURE);
}

int	xml_check_open_token(t_token *t)
{
  t_token	*tmp;

  tmp = t->next;
  while (tmp)
    {
      if (my_strcmp(tmp->name, t->name) == 0)
	{
	  if (tmp->token != TK_END_NODE)
	    xml_put_synt_error(1,
			       tmp->content,
			       "Missing close balise char.\n",
			       tmp->line);
	  else
	    return (EXIT_SUCCESS);
	  return (EXIT_FAILURE);
	}
      tmp = tmp->next;
    }
  xml_put_error("[", t->line, t->content, "] have no close balise");
  return (EXIT_FAILURE);
}

int	xml_check_close_token(t_token *t)
{
  t_token	*tmp;

  tmp = t->prev;
  if (xml_check_presence(t->content, "</", "</>") == EXIT_FAILURE)
    {
      xml_put_synt_error(1, t->content, "No end balise char.\n", t->line);
      return (EXIT_FAILURE);
    }
  while (tmp)
    {
      if (my_strcmp(tmp->name, t->name) == 0)
	{
	  if (tmp->token != TK_OPEN_NODE)
	    xml_put_error("[", tmp->line, tmp->content,
			  "] is not a valid open balise.");
	  else
	    return (EXIT_SUCCESS);
	}
      tmp = tmp->prev;
    }
  xml_put_error("[", t->line, t->content, "] have no open balise");
  return (EXIT_FAILURE);
}

int	xml_check_s_token(t_token *t)
{
  if (xml_check_presence(t->content, "/>", "</>") == EXIT_FAILURE)
    {
      xml_put_synt_error(my_strlen(t->content), t->content,
			 "No end balise char.\n", t->line);
    }
  return (EXIT_SUCCESS);
}

int	xml_check_token(t_token *t)
{
  while (t)
    {
      if (t->token == TK_OPEN_NODE && xml_check_open_token(t) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (t->token == TK_END_NODE && xml_check_close_token(t) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      if (t->token == TK_SINGLE_NODE && (xml_check_s_token(t)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      t = t->next;
    }
  return (EXIT_SUCCESS);
}
