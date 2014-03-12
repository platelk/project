/*
** display_antialiasing.c for antialiasing in /home/guiho_r/tek1/rt/src/display
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  3 05:57:37 2012 ronan guiho
** Last update Sun Jun  3 15:16:42 2012 ronan guiho
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<pthread.h>
#include	<sys/time.h>

#include	"global.h"
#include	"parse.h"
#include	"raytracer.h"
#include	"display.h"
#include        "export.h"
#include        "thread.h"
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

int		antialiasing(t_thread *thread, double x, double y, \
			     double antialiasing)
{
  double	ydom[2];
  double	xdom[2];
  double	ref_antialiasing;

  xdom[MAX] = x + 0.5F;
  ydom[MAX] = y + 0.5F;
  ydom[MIN] = y - 1.0F;
  restat_color(&thread->color);
  ref_antialiasing = antialiasing;
  while ((ydom[MIN] += ECHANTILLON) < ydom[MAX])
    {
      xdom[MIN] = x - 1.0F;
      while ((xdom[MIN] += ECHANTILLON) < xdom[MAX])
	{
	  display_image_calc(thread, antialiasing, xdom, ydom);
	  antialiasing = ref_antialiasing;
	}
    }
  thread->color.red /= (NROOKS * antialiasing);
  thread->color.green /= (NROOKS * antialiasing);
  thread->color.blue /= (NROOKS * antialiasing);
  if (thread->mode == TYPE_NORMAL)
    mlx_ppti(thread->thread_image, &thread->color, x, y);
  return (EXIT_SUCCESS);
}
