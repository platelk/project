/*
** get_pos.c for get_pos in /home/vink/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  8 14:40:08 2012 kevin platel
** Last update Sat Mar 10 17:00:24 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "scene.h"
#include "camera.h"
#include "object.h"
#include "light.h"

t_cam	*get_pos(t_cam *new, t_attr *attr)
{
  if (my_strcmp(attr->name, "pos_x") == 0)
    {
      new->x = my_getnbr(attr->value);
      attr = attr->next;
	if (attr != NULL && my_strcmp(attr->name, "pos_y") == 0)
	  {
	    new->y = -1 * my_getnbr(attr->value);
	    attr = attr->next;
	    if (attr != NULL && my_strcmp(attr->name, "pos_z") == 0)
	      {
		new->z = -1 * my_getnbr(attr->value);
		new->attr = attr->next;
	      }
	  }
	new->attr = attr;
    }
  else
    {
      if (attr == NULL)
	my_printf("You need to give 3 position: x, y, z\n");
      else
	my_printf("you need to give pose like : pos_x=VALUE\n");
      return (NULL);
    }
  return (new);
}

t_object	*get_pos_obj(t_object *new, t_attr *attr)
{
  if (my_strcmp(attr->name, "pos_x") == 0)
    {
      new->x = my_getnbr(attr->value);
      attr = attr->next;
	if (attr != NULL && my_strcmp(attr->name, "pos_y") == 0)
	  {
	    new->y = -1 * my_getnbr(attr->value);
	    attr = attr->next;
	    if (attr != NULL && my_strcmp(attr->name, "pos_z") == 0)
	      {
		new->z = -1 * my_getnbr(attr->value);
		new->attr = attr->next;
	      }
	  }
	new->attr = attr;
    }
  else
    {
      if (attr == NULL)
	my_printf("You need to give 3 position: x, y, z\n");
      else
	my_printf("you need to give pose like : pos_x=VALUE\n");
      return (NULL);
    }
  return (new);
}

t_light	*get_pos_light(t_light *new, t_attr *attr)
{
  if (my_strcmp(attr->name, "pos_x") == 0)
    {
      new->x = my_getnbr(attr->value);
      attr = attr->next;
	if (attr != NULL && my_strcmp(attr->name, "pos_y") == 0)
	  {
	    new->y = -1 * my_getnbr(attr->value);
	    attr = attr->next;
	    if (attr != NULL && my_strcmp(attr->name, "pos_z") == 0)
	      {
		new->z = -1 * my_getnbr(attr->value);
		new->attr = attr->next;
	      }
	  }
	new->attr = attr;
    }
  else
    {
      if (attr == NULL)
	my_printf("You need to give 3 position: x, y, z\n");
      else
	my_printf("you need to give pose like : pos_x=VALUE\n");
      return (NULL);
    }
  return (new);
}
