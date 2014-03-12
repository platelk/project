/*
** display_aliasing.c for display in /home/guiho_r/tek1/rt/src/display
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  3 05:45:47 2012 ronan guiho
** Last update Sun Jun  3 05:52:15 2012 ronan guiho
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
pthread_mutex_t mutex;

int		aliasing(t_thread *thread, double x, double y, \
			  double aliasing)
{
  double	ymax;
  double	xdom[2];

  ymax = y + aliasing;
  xdom[MAX] = x + aliasing;
  pthread_mutex_lock(&mutex);
  if (calc_management(global_thread, &thread->color, x, y))
    return (EXIT_FAILURE);
  pthread_mutex_unlock(&mutex);
  while ((y < ymax) && (y < thread->size[HEIGHT]))
    {
      xdom[MIN] = x;
      while ((xdom[MIN] < xdom[MAX]) && (xdom[MIN] < \
					 thread->size[WIDTH]))
	{
	  if (thread->mode == TYPE_NORMAL)
	    if (mlx_ppti(thread->thread_image, &thread->color, xdom[MIN], y))
	      return (EXIT_FAILURE);
	  xdom[MIN] += 1.000;
	}
      y += 1.000;
    }
  return (EXIT_SUCCESS);
}
