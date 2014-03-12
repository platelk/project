/*
** xml_print_list.c for test in /home/vink/projet/graph/xml
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Sat May  5 18:56:27 2012 kevin platel
** Last update Sat May 12 22:41:34 2012 kevin platel
*/

#include	<stdio.h>

#include	"my.h"
#include	"xml_tree.h"
#include	"xml_token.h"
#include	"xml_attr.h"

t_xtree	*xml_print_tree(t_xtree *t, int i)
{
  int	a;
  t_attr	*tmp;

  if (!t)
    return (NULL);
  a = i;
  while (--i > 0)
    my_putstr("    ");
  my_putstr("|__ ");
  my_putstr(t->name);
  my_putstr("_");
  my_putstr("[");
  my_putstr(t->content);
  my_putstr("]");
  tmp = t->attr;
  my_putstr(" {");
  while (tmp)
    {
      my_putstr(tmp->name);
      my_putstr("=\'");
      my_putstr(tmp->content);
      my_putstr("\'");
      if (tmp->next)
	my_putstr(", ");
      tmp = tmp->next;
    }
  my_putstr("}");
  if (t->sun != NULL)
    {
      my_putstr("\n");
      xml_print_tree(t->sun, a + 1);
    }
  else
    my_putstr("\n");
  return (xml_print_tree(t->next, a));
}

char	*xml_print_token(int i)
{
  if (i == TK_NULL)
    return (" {NULL}");
  if (i == TK_EMPTY)
    return (" {EMPTY}");
  if (i == TK_INV_NODE)
    return (" {INV_NODE}");
  if (i == TK_OPEN_NODE)
    return (" {OPEN_NODE}");
  if (i == TK_END_NODE)
    return (" {END_NODE}");
  if (i == TK_SINGLE_NODE)
    return (" {SINGLE_NODE}");
  if (i == TK_TERM_NODE)
    return (" {TERM_NODE}");
  return ("{NOTHING}");
}

void	xml_print_list(t_token *t)
{
  while (t)
    {
      printf("-------------\n");
      printf("LINE : %d\n", t->line);
      printf("TOKEN : %s\n", xml_print_token(t->token));
      printf("CONTENT : [%s]\n", t->content);
      printf("NAME : (%s)\n", t->name);
      printf("-------------\n");
      t = t->next;
    }
}
