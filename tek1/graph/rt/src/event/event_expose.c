/*
** event_expose.c for raytracer in /home/leprov_a//depot/rt/src/event
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  1 21:10:03 2012 alexis leprovost
** Last update Wed May 30 01:43:01 2012 ronan guiho
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"raytracer.h"
#include	"global.h"
#include	"mlx.h"
#include	"my.h"

int	event_expose(t_global *global)
{
  int	i;

  i = -1;
  if (!global || !global->window)
    return (EXIT_FAILURE);
  while (++i < global->info.nbr_thread)
    mlx_put_image_to_window(global->window->mlx_ptr,
			    global->window->win_ptr,
			    global->thread[i].thread_image->ptr,
			    global->thread[i].thread_atribution[X_MIN], -3);
  return (EXIT_SUCCESS);
}
