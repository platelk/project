/*
** display_image_calc.c for display in /home/guiho_r/tek1/rt/src/display
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  3 04:48:54 2012 ronan guiho
** Last update Sun Jun  3 15:17:08 2012 ronan guiho
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

int	display_image_calc(t_thread *thread, double antialiasing,
			   double *xdom, double *ydom)
{
  t_color	color;

  while ((--antialiasing + 1) > 0)
    {
      pthread_mutex_lock(&mutex);
      calc_management(global_thread, &color, RL(xdom[MIN]), RL(ydom[MIN]));
      pthread_mutex_unlock(&mutex);
      add_color(&thread->color, &color);
    }
  return (EXIT_SUCCESS);
}
