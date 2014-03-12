/*
** obj_print.c for obj in /home/vink/projet/graph/rt/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May  8 18:40:37 2012 kevin platel
** Last update Tue May  8 18:53:11 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#include	"object.h"

void	obj_object_print(t_object *obj)
{
  write(1, "LOL\n", 4);
  while (obj)
    {
      printf("-----------\n");
      printf("Type : %d", obj->type);
      printf("pos : x = %f, y = %f, z = %f\n", obj->position[X], obj->position[Y], obj->position[Z]);
      printf("-----------\n");
      obj = obj->next;
    }
}
