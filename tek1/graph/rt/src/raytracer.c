/*
** raytracer.c for raytracer in /home/leprov_a//depot/rt/src
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Thu May 31 23:49:17 2012 alexis leprovost
** Last update Wed Dec  5 21:04:43 2012 kevin platel
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

t_global	*global_thread;

int		main_option_server(t_global *global, t_xtree *tree)
{
  global->scene = NULL;
  global->count_trame = 0;
  my_putstr("[*] Raytracer: Creation of the window ...");
  if ((global->window = obj_create_window(global, tree)) == NULL)
    return (my_puterror(" \033[31mFail !\033[0m\n"));
  my_putstr(" \033[32mDone !\033[00m\n");
  my_putstr("[*] Raytracer: Creation of the scene ...");
  if (!(global->scene = obj_create_scene(tree, global->window->mlx_ptr)))
    return (my_puterror(" \033[31mFail !\033[0m\n"));
  my_putstr(" \033[32mDone !\033[00m\n");
  init_box(global->scene->object);
  if ((server_main(global->info.port)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  mlx_key_hook(global->window->win_ptr, &event_key, global);
  mlx_expose_hook(global->window->win_ptr, &event_expose, global);
  mlx_loop(global->window->mlx_ptr);
  return (EXIT_SUCCESS);
}

int			main_option_client(t_global *global, t_xtree *tree)
{
  char			*hostname;

  global->scene = NULL;
  my_putstr("[*] Raytracer: Creation of the window ...");
  if ((global->window = obj_create_window(global, tree)) == NULL)
    return (my_puterror(" \033[31mFail !\033[0m\n"));
  my_putstr(" \033[32mDone !\033[00m\n");
  my_putstr("[*] Raytracer: Creation of the scene ...");
  if ((global->scene = obj_create_scene			\
       (tree, global->window->mlx_ptr)) == NULL)
    return (my_puterror(" \033[31mFail !\033[0m\n"));
  my_putstr(" \033[32mDone !\033[00m\n");
  hostname = ((t_client_info *)global->info.arg)->hostname;
  init_box(global->scene->object);
  if ((client_main(hostname, global->info.port)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		main_option(t_global *global, t_xtree *tree)
{
  t_main_option	tab_func[NB_MAIN_OPTION + 1];

  tab_func[0] = &main_option_server;
  tab_func[1] = &main_option_client;
  tab_func[2] = &main_option_normal;
  if ((tab_func[global->info.type](global, tree)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
  t_global	*global;
  t_xtree	*tree;

  srandom(time(0) * getpid());
  if ((global = malloc(sizeof(*global))) == NULL)
    return (EXIT_FAILURE);
  global_thread = global;
  global->object = NULL;
  global->param = POSITION;
  if (!get_cmd_line(ac, av, &(global->info)))
    return (EXIT_FAILURE);
  my_putstr("[*] Raytracer: Creation of the tree ...");
  if ((tree = xml_parser(global->info.xml)) == NULL)
    return (my_puterror(" \033[31mFail !\033[00m\n"));
  my_putstr(" \033[32mDone !\033[00m\n");
  if ((main_option(global, tree)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
