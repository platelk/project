/*
** obj_create_window.c for obj in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:29:07 2012 kevin platel
** Last update Sun Jun  3 16:29:07 2012 kevin platel
*/

#include	<stdlib.h>

#include	"mlx.h"
#include	"init.h"
#include	"my.h"
#include	"window.h"
#include	"xml_chr.h"
#include	"xml_tree.h"

void        obj_create_window_n(t_window *window, t_xtree *tmp)
{
  window->y_win = my_getnbr(xml_find_attr(tmp->attr, STRING_Y_WIN));
  if (window->y_win <= 0)
    window->y_win = NUM_WIN_Y;
  window->x_win = my_getnbr(xml_find_attr(tmp->attr, STRING_X_WIN));
  if (window->x_win <= 0)
    window->x_win = NUM_WIN_X;
  window->name_win = xml_find_attr(tmp->attr, STRING_WIN_NAME);
  window->attr = tmp->attr;
}

t_window	*obj_create_window(t_global *global, t_xtree *tree)
{
  t_normal_info	*normal_info;
  t_window	*window;
  t_xtree	*tmp;

  normal_info = NULL;
  if (global->info.type == TYPE_NORMAL || global->info.type == TYPE_SERVER)
    normal_info = (t_normal_info *)global->info.arg;
  if ((tmp = xml_find_in_tree(tree, STRING_WINDOW, 0)) == NULL ||
      (window = malloc(sizeof(*window))) == NULL)
    return (NULL);
  obj_create_window_n(window, tmp);
  if ((window->mlx_ptr = mlx_init()) == 0)
    return (NULL);
  if (global && (global->info.type == TYPE_NORMAL ||
		 global->info.type == TYPE_SERVER) && normal_info->mute == 0)
    window->win_ptr = mlx_new_window(window->mlx_ptr, window->x_win,
				     window->y_win, window->name_win);
  tmp = xml_find_in_tree(tree, "window/background", 0);
  if (tmp)
    window->background = init_image(window->mlx_ptr, tmp->content,
				    window->x_win, window->y_win);
  else
    window->background = NULL;
  return (window);
}
