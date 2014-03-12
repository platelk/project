/*
** obj_create_window.c for obj in /home/vink/projet/graph/xml/obj_src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Mon May  7 14:37:31 2012 kevin platel
** Last update Mon May  7 15:47:59 2012 kevin platel
*/

#include	<stdlib.h>

#include	"window.h"
#include	"xml_chr.h"
#include	"xml_tree.h"

t_window	*obj_create_window(t_xtree *tree)
{
  t_window	*window;
  t_xtree	*tmp;

  tmp = xml_find_in_tree(tree, STRING_WINDOW);
  if (!tmp)
    return (NULL);
  window = malloc(sizeof(*window));
  if (!window)
    return (NULL);
  window->y_win = my_getnbr(xml_find_attr(tmp->attr, STRING_Y_WIN));
  if (window->y_win <= 0)
    window->y_win = NUM_WIN_Y;
  window->x_win = my_getnbr(xml_find_attr(tmp->attr, STRING_X_WIN));
  if (window->x_win <= 0)
    window->x_win = NUM_WIN_X;
  window->name_win = xml_find_attr(tmp->attr, STRING_WIN_NAME);
  window->attr = tmp->attr;
  /*
  ** A finir
  */
  return (window);
}
