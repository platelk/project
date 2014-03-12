/*
** display_image.c for raytracer in /home/leprov_a//depot/rt/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 13:44:50 2012 alexis leprovost
** Last update Sun Jun  3 17:10:49 2012 alexis leprovost
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<pthread.h>
#include	<sys/time.h>

#include	"parse.h"
#include	"raytracer.h"
#include        "export.h"
#include        "thread.h"
#include	"display.h"
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
pthread_mutex_t mutex;

t_color		*display_image_pixel(t_thread *thread, double x, double y, \
				     int flag)
{
  if (thread->antialiasing > 0.00)
    antialiasing(thread, x, y, thread->antialiasing);
  else
    aliasing(thread, x, y, flag);
  return (&thread->color);
}

void		*display_image_thread(void *arg)
{
  double	y;
  double	flag;
  t_thread	*thread;
  t_normal_info	*normal_info;

  thread = (t_thread *)arg;
  normal_info = NULL;
  if (thread->mode == TYPE_NORMAL)
    normal_info = (t_normal_info *)global_thread->info.arg;
  flag = thread->antialiasing;
  flag = (flag < 0.000) ? (flag * (-1.000)) : (1.000);
  y = thread->thread_atribution[Y_MIN];
  while (y < thread->thread_atribution[Y_MAX])
    {
      display_image_thread_x(y, thread, flag, normal_info);
      y += flag;
    }
  if (thread->thread_atribution[DISPLAY] != ON)
    pthread_exit(EXIT_SUCCESS);
  return (NULL);
}

static int	display_image_atribution(t_global *global)
{
  int		i;
  int		value;
  int		atribution[2];

  i = 0;
  value = 0;
  pthread_mutex_init(&mutex, NULL);
  atribution[0] = global->window->x_win / THREAD_COUNT;
  atribution[1] = global->window->x_win % THREAD_COUNT;
  while (i < THREAD_COUNT)
    {
      display_fill_thread(i, value, atribution, global);
      value = value + atribution[0];
      i++;
    }
  global->thread[i - 1].thread_atribution[X_MAX] = value + atribution[1];
  global->thread[i - 1].thread_atribution[DISPLAY] = ON;
  return (EXIT_SUCCESS);
}

int		display_image(t_global *global)
{
  int		status;
  int		count_export;
  t_normal_info	*normal_info;

  status = 1;
  normal_info = NULL;
  if (global->info.type == TYPE_NORMAL)
      normal_info = (t_normal_info *)global->info.arg;
  global->info.nbr_thread = (global->info.nbr_thread > MAX_THREAD || \
			     global->info.nbr_thread > global->window->x_win) \
    ? 1 : global->info.nbr_thread;
  display_image_atribution(global);
  count_export = 0;
  while (global->scene && status)
    {
      count_export = display_image_proccess(global, normal_info, \
					    count_export);
      if (global->scene->next == NULL)
	status = 0;
      else
	global->scene = global->scene->next;
    }
  return (EXIT_SUCCESS);
}
