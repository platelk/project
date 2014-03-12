/*
** display_image_thread.c for display in /home/guiho_r/tek1/rt/src/display
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  3 05:16:28 2012 ronan guiho
** Last update Sun Jun  3 15:18:57 2012 ronan guiho
*/

#include	<time.h>
#include	<stdio.h>
#include	<stdlib.h>
#include	<pthread.h>
#include	<sys/time.h>

#include	"parse.h"
#include	"raytracer.h"
#include        "export.h"
#include        "thread.h"
#include	"global.h"
#include	"display.h"
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

int	display_image_thread_x(double y, t_thread *thread,
			       double flag, t_normal_info *normal_info)
{
  double		x;

  x = thread->thread_atribution[X_MIN];
  while (x < thread->thread_atribution[X_MAX])
    {
      display_image_pixel(thread, x, y, flag);
      if (thread->thread_atribution[DISPLAY] == ON)
	{
	  global_thread->count_pixel =	\
	    progressbar_calc(global_thread->count_pixel);
	}
      global_thread->count_pixel++;
      x += flag;
    }
  if (thread->mode == TYPE_NORMAL && normal_info && normal_info->mute == 0)
    if (thread->thread_atribution[DISPLAY] == ON)
      event_expose(global_thread);
  return (EXIT_SUCCESS);
}

int	display_image_proccess(t_global *global, t_normal_info *normal_info,
			       int count_export)
{
  int			i;
  int			i1;

  i1 = -1;
  init_box(global->scene->object);
  while (++i1 < (THREAD_COUNT - 1))
    {
      global->thread[i1].antialiasing = global_thread->scene->antialiasing;
      if ((pthread_create(&global->thread[i1].thread_p, NULL, \
			  display_image_thread, &global->thread[i1])) < 0)
	return (EXIT_FAILURE);
    }
  global->thread[i1].antialiasing = global_thread->scene->antialiasing;
  display_image_thread(&global->thread[i1]);
  i = -1;
  while (++i < (THREAD_COUNT - 1))
    pthread_join(global->thread[i].thread_p, NULL);
  if (global->info.type == TYPE_NORMAL && normal_info->mute == 0)
    event_expose(global);
  if (global->info.type == TYPE_NORMAL)
    {
      if (normal_info && normal_info->exp != NULL)
	determ_export(global, normal_info->exp, count_export++);
    }
  return (count_export);
}
