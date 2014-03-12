/*
** export_img.c for export in /home/guiho_r/tek1/rt/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu May 24 14:54:27 2012 ronan guiho
** Last update Thu May 24 20:54:39 2012 ronan guiho
*/

#include <stdlib.h>

#include "init.h"
#include "image.h"
#include "raytracer.h"

t_image		*export_image(t_global *global)
{
  int		i;
  int		x;
  int		y;
  int		i1;
  int		i2;
  t_image	*export;

  i = 0;
  if ((export = init_image(global->window->mlx_ptr, NULL,\
			   global->window->x_win,\
			   global->window->y_win)) == NULL)
    return (NULL);
  while (i < global->info.nbr_thread)
    {
      y = -1;
      while (++y < global->thread[i].thread_atribution[Y_MAX])
	{
	  x = -1;
	  while (++x < (global->thread[i].thread_atribution[X_MAX] - global->thread[i].thread_atribution[X_MIN]))
	    {
	      i1 = (y * global->thread[i].thread_image->sizeline) + \
		(x * (global->thread[i].thread_image->bpp / 8));
	      i2 = (y * export->sizeline) + ((global->thread[i].thread_atribution[X_MIN] + x) * (export->bpp / 8));
	      export->data[i2] = global->thread[i].thread_image->data[i1];
	      export->data[i2 + 1] = global->thread[i].thread_image->data[i1 + 1];
	      export->data[i2 + 2] = global->thread[i].thread_image->data[i1 + 2];
	    }
	}
      i++;
    }
  return (export);
}
