/*
** xml_token_list.c for xml in /home/vink/projet/graph/rt/src/xml_src/src
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:24:47 2012 kevin platel
** Last update Sun Jun  3 16:24:47 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>

#include	"my_strtok.h"
#include	"xml_char.h"
#include	"xml_token.h"
#include	"xml_utils.h"
#include	"my.h"

char	*xml_get_name_node(char *s)
{
  char	**tab;
  char	*tmp;

  tmp = NULL;
  tab = my_strtok(s, "<> /\\\n\t", TOK_DELIM);
  if (tab)
    tmp = my_strdup(tab[0]);
  my_free_tab(tab);
  return (tmp);
}

int	xml_get_token(char *s)
{
  char	**tab;
  int	ret;

  ret = -1;
  if (!s)
    return (TK_NULL);
  tab = my_strtok(s, "<>", TOK_DELIM);
  if (tab == NULL || tab[0] == NULL)
    ret = (TK_EMPTY);
  else if (xml_len_tab(tab) > 1)
    ret = (TK_TERM_NODE);
  else if (tab[0][0] == SLASH_CHAR)
    ret = (TK_END_NODE);
  else if (tab[0][my_strlen(tab[0]) - 1] == SLASH_CHAR)
    ret = (TK_SINGLE_NODE);
  else
    ret = (TK_OPEN_NODE);
  my_free_tab(tab);
  return (ret);
}

t_token	*xml_add_in_token_list(char *s, t_token *token, int line)
{
  t_token	*new;

  new = malloc(sizeof(*new));
  new->line = line;
  new->token = xml_get_token(s);
  new->name = xml_get_name_node(s);
  new->content = my_strdup(s);

  new->prev = token;
  new->next = NULL;
  if (token)
    token->next = new;
  return (new);
}
