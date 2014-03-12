/*
** export_img.c for export in /home/guiho_r/tek1/rt/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu May 24 14:54:27 2012 ronan guiho
** Last update Sun Jun  3 14:27:49 2012 jordan vanwalleghem
*/

#include <stdlib.h>

#include "init.h"
#include "image.h"
#include "raytracer.h"

t_global *global_thread;

void		export_image_fill(t_image *export, int i,
				   int i1, int i2)
{
  export->data[i2] = global_thread->thread[i].thread_image->data[i1];
  export->data[i2 + 1] = global_thread->thread[i].thread_image->data[i1 + 1];
  export->data[i2 + 2] = global_thread->thread[i].thread_image->data[i1 + 2];
}

t_image		*export_image(t_global *g, int i, int x, int y)
{
  int		i1;
  int		i2;
  t_image	*export;

  if ((export = init_image(g->window->mlx_ptr, NULL, g->window->x_win,
			   g->window->y_win)) == NULL)
    return (NULL);
  while (++i < g->info.nbr_thread)
    {
      while (++y < g->thread[i].thread_atribution[Y_MAX])
	{
	  while (++x < (g->thread[i].thread_atribution[X_MAX]
			- g->thread[i].thread_atribution[X_MIN]))
	    {
	      i1 = (y * g->thread[i].thread_image->sizeline) + \
		(x * (g->thread[i].thread_image->bpp / 8));
	      i2 = (y * export->sizeline)
		+ ((g->thread[i].thread_atribution[X_MIN] + x) * (export->bpp / 8));
	      export_image_fill(export, i, i1, i2);
	    }
	  x = -1;
	}
      y = -1;
    }
  return (export);
}
