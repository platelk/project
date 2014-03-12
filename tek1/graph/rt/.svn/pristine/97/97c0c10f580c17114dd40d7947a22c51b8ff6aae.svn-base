/*
** display_fill_thread.c for display in /home/guiho_r/tek1/rt/src/display
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  3 05:25:42 2012 ronan guiho
** Last update Sun Jun  3 15:08:27 2012 ronan guiho
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<pthread.h>
#include	<sys/time.h>

#include	"parse.h"
#include	"raytracer.h"
#include        "export.h"
#include        "thread.h"
#include	"global.h"
#include	"color.h"
#include	"event.h"
#include	"utils.h"
#include	"calc.h"
#include	"init.h"
#include	"free.h"
#include	"mlx.h"
#include	"my.h"
#include	"box.h"
#include	"determ_export.h"

t_global	*global_thread;

int	display_fill_thread(int i, int value, int *atribution, \
			    t_global *global)
{
  global->thread[i].mode = global->info.type;
  global->thread[i].antialiasing = global_thread->scene->antialiasing;
  global->thread[i].size[WIDTH] = global_thread->window->x_win;
  global->thread[i].size[HEIGHT] = global_thread->window->y_win;
  global->thread[i].thread_atribution[ID] = i;
  global->thread[i].thread_atribution[DISPLAY] = OFF;
  global->thread[i].thread_atribution[X_MIN] = value;
  global->thread[i].thread_atribution[X_MAX] = value + atribution[0];
  global->thread[i].thread_atribution[Y_MIN] = 0;
  global->thread[i].thread_atribution[Y_MAX] = global->window->y_win;
  global->thread[i].thread_image = init_image(global->window->mlx_ptr, NULL, \
					      global->thread[i].\
					      thread_atribution[X_MAX] - \
					      global->thread[i].\
					      thread_atribution[X_MIN], \
					      global->thread[i].\
					      thread_atribution[Y_MAX]);
  return (EXIT_SUCCESS);
}
