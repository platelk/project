/*
** normal_mode.c for raytracer in /home/leprov_a//rt/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun Jun  3 17:38:22 2012 alexis leprovost
** Last update Sun Jun  3 17:44:24 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<time.h>
#include	<sys/types.h>
#include	<unistd.h>

#include	"client.h"
#include	"server.h"
#include	"raytracer.h"
#include	"global.h"
#include	"parse.h"
#include	"display.h"
#include	"init.h"
#include	"event.h"
#include	"box.h"
#include	"mlx.h"
#include	"my.h"
#include	"xml_parser.h"
#include	"xml_tree.h"
#include	"obj_create.h"
#include	"verbose_mode.h"

static	int	option_normal(t_global *global, t_xtree *tree,
			      t_normal_info *normal_info)
{
  global->stereoscopique = obj_create_3D(global->window->x_win,
					 global->window->y_win,
					 global->window->mlx_ptr,
					 tree);
  if (normal_info->verbose == 0)
    {
      init_box(global->scene->object);
      if (global->stereoscopique != NULL && global->stereoscopique->size > 0)
	return (display_stereoscopique(global));
      write(1, "[*] Raytracer: Calcul of image ...", 35);
      if (display_image(global))
	return (my_puterror(" \033[31mFail !\033[0m\n"));
      my_putstr(" \033[32mDone !\033[00m\n");
    }
  else
    verbose_mode(global);
  if (normal_info->mute == 0 &&  normal_info->verbose == 0)
    {
      mlx_key_hook(global->window->win_ptr, &event_key, global);
      mlx_mouse_hook(global->window->win_ptr, &event_mouse, global);
      mlx_expose_hook(global->window->win_ptr, &event_expose, global);
      mlx_loop(global->window->mlx_ptr);
    }
  return (EXIT_SUCCESS);
}

int		main_option_normal(t_global *global, t_xtree *tree)
{
  t_normal_info	*normal_info;

  global->scene = NULL;
  normal_info = (t_normal_info *)global->info.arg;
  if (normal_info->verbose == 1)
    global->info.type = TYPE_CLIENT;
  global->count_pixel = 0.0;
  my_putstr("[*] Raytracer: Creation of the window ...");
  if ((global->window = obj_create_window(global, tree)) == NULL)
    return (my_puterror(" \033[31mFail !\033[0m\n"));
  my_putstr(" \033[32mDone !\033[00m\n");
  my_putstr("[*] Raytracer: Creation of the scene ...");
  if (!(global->scene = obj_create_scene(tree, global->window->mlx_ptr)))
    return (my_puterror(" \033[31mFail !\033[00m\n"));
  my_putstr(" \033[32mDone !\033[00m\n");
  option_normal(global, tree, normal_info);
  return (EXIT_SUCCESS);
}
