/*
** event_mouse.c for raytracer in /home/leprov_a//depot/rt/src/event
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 31 15:33:39 2012 alexis leprovost
** Last update Sat Jun  2 09:33:28 2012 jordan vanwalleghem
*/

#include	<stdlib.h>

#include	"mousecode.h"
#include	"global.h"
#include	"object.h"
#include	"display.h"
#include	"init.h"
#include	"calc.h"
#include	"box.h"

int	event_mouse(int button, int x, int y, t_global *global)
{
  t_object	*tmp;
  double	vector[NB_DIMENSION];
  t_detail	detail;

  if (init_detail(&detail) || global == NULL || global->scene == NULL)
    return (EXIT_FAILURE);
  tmp = global->scene->object;
  if (button == CLICK_LEFT && !calc_direction_vector(global, vector, x, y))
    {
      while (tmp)
	{
	  if (inter_ray_box(global->scene->camera, vector, tmp))
	    tmp->inter(global->scene->camera, tmp, &detail, vector);
	  tmp = tmp->next;
	}
      global->object = detail.object;
    }
  if ((button == SCROLL_UP || button == SCROLL_DOWN))
    {
      if (global->scene->camera)
	global->scene->camera->fov += ((button == SCROLL_UP ? 1 : -1) * 10);
      display_image(global);
    }
  return (EXIT_SUCCESS);
}
