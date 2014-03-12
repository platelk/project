/*
** display_stereoscopique.c for raytracer in /home/leprov_a//rt/src/display
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun Jun  3 16:57:39 2012 alexis leprovost
** Last update Sun Jun  3 17:08:44 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"mlx.h"
#include	"raytracer.h"
#include	"keycode.h"
#include	"global.h"
#include	"color.h"
#include	"camera.h"
#include	"calc.h"
#include	"free.h"

static	int	refresh_3D(t_global *global)
{
  if (global == NULL)
    return (EXIT_FAILURE);
  mlx_put_image_to_window(global->window->mlx_ptr,
			  global->window->win_ptr,
			  global->stereoscopique->image->ptr, 0, 0);
  return (EXIT_SUCCESS);
}

static	int	quit_3D(int keycode, t_global *global)
{
  if (keycode == ESC)
    {
      free_global(global);
      exit(EXIT_SUCCESS);
    }
  return (EXIT_SUCCESS);
}

static	int	color_3D(t_color *color)
{
  if (color == NULL)
    return (EXIT_FAILURE);
  color[2].red = color[0].red;
  color[2].green = color[1].green;
  color[2].blue = color[1].blue;
  return (EXIT_SUCCESS);
}

static	int	wait_3D(t_global *global)
{
  if (global == NULL)
    return (EXIT_FAILURE);
  mlx_key_hook(global->window->win_ptr, &quit_3D, global);
  mlx_loop(global->window->mlx_ptr);
  return (EXIT_SUCCESS);
}

int		display_stereoscopique(t_global *global)
{
  t_color	color[3];
  int	y;
  int	x;

  y = -1;
  if (global == NULL || global->scene == NULL || global->window == NULL ||
      global->scene->camera == NULL || global->stereoscopique == NULL)
    return (EXIT_FAILURE);
  global->scene->camera->position[Y] += (global->stereoscopique->size / 2);
  while (++y < global->window->y_win)
    {
      x = -1;
      while (++x < global->window->x_win)
	{
	  calc_management(global, &color[0], (double)x, (double)y);
	  global->scene->camera->position[Y] -= (global->stereoscopique->size);
	  calc_management(global, &color[1], (double)x, (double)y);
	  global->scene->camera->position[Y] += (global->stereoscopique->size);
	  color_3D(color);
	  mlx_ppti(global->stereoscopique->image, &color[2], x, y);
	}
      refresh_3D(global);
    }
  return (wait_3D(global));
}
