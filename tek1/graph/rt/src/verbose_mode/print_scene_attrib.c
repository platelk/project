/*
** print_scene_attrib.c for print_scene_atrib in /home/jordan/Projets/Epitech/rt/verbose_mode
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Sat Jun  2 03:49:47 2012 jordan vanwalleghem
** Last update Sun Jun  3 19:52:22 2012 alexis leprovost
*/

#include	<stdlib.h>

#include "my.h"
#include "scene.h"
#include "object.h"
#include "verbose_mode.h"

void	count_scenes(t_scene *scenes)
{
  int x;

  x = 0;
  while (scenes)
    {
      scenes = scenes->next;
      x++;
    }
  my_putnbr(x);
  if (x == 1)
    my_putstr(" scene.\n\n");
  else
    my_putstr(" scenes.\n\n");
}

int	count_camera(t_camera *camera)
{
  int x;

  x = 0;
  if (camera == NULL)
    {
      my_putstr("aucune");
      return (EXIT_FAILURE);
    }
  while (camera)
    {
      camera = camera->next;
      x++;
    }
  my_putnbr(x);
  return (EXIT_SUCCESS);
}

int    count_object(t_object *object)
{
  int x;

  x = 0;
  if (object == NULL)
    {
      my_putstr("La scene ne comporte aucun objet.\n\n");
      return (0);
    }
  my_putstr("La scene comporte ");
  while (object->prev)
    object = object->prev;
  while (object)
    {
      object = object->next;
      x++;
    }
  my_putnbr(x);
  my_putstr(" objets.\n\n");
  my_putstr("\t[Attributs des objets]\n");
  return (x);
}

void	print_scene_atrib(t_scene *scenes)
{
  while (scenes->prev)
    scenes = scenes->prev;
  count_scenes(scenes);
  while (scenes)
    {
      my_putstr("\t[Detail scene ");
      my_putnbr(scenes->id);
      my_putstr("]\n");
      my_putstr("La scene comporte ");
      count_camera(scenes->camera);
      my_putstr(" caméras\n\n");
      my_putstr("\t[Detail objets]\n");
      if (count_object(scenes->object) > 0)
	object_details(scenes->object);
      scenes = scenes->next;
    }
}
