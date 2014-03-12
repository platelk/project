/*
** server_listen.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 16:06:02 2012 ronan guiho
** Last update Mon May 28 21:50:23 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "init.h"
#include "global.h"
#include "server.h"

t_client *list;
t_global *global_thread;

int		server_listen(SOCKET ssock)
{
  list = NULL;
  if ((server_ping_start()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((server_management_start()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((global_thread->thread[0].thread_image = init_image(global_thread->window->mlx_ptr,
							  NULL,
							  global_thread->window->x_win,
							  global_thread->window->y_win)) == NULL)
      return (EXIT_FAILURE);
  printf("[*] Raytracer: Clustering: Listen...\n");
  while (42)
    {
      if ((server_client_connected(&list, ssock)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
