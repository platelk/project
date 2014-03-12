/*
** fill_objects.c for fill_objects in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Feb 17 09:26:20 2012 harold ozouf
** Last update Sun Mar 11 14:35:00 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"str.h"
#include	"xfnt.h"
#include	"finding_elm.h"
#include	"convert.h"
#include	"fill_struct_scene.h"
#include	"aff.h"
#include	"struct.h"
#include	"node.h"
#include	"object.h"
#include	"fill_scene.h"
#include	"fill_objects.h"

int	get_type(char *type, char **cores)
{
  int	i;

  i = -1;
  while (cores[++i] != NULL)
    if (my_strcmp(type, cores[i]) == 0)
      return (i);
  xerror(type, "shape do not exist.");
  return (0);
}

void	add_obj(t_shape **sc, t_node *root, char **cores, add_shape *sh)
{
  t_shape      	*p;
  char		*type;
  t_node	*nd;

  nd = get_node("object/", root);
  p = xmalloc(sizeof(*p));
  p->pos = xmalloc(sizeof(*(p->pos)));
  p->rot = xmalloc(sizeof(*(p->rot)));
  p->mat = xmalloc(sizeof(*(p->mat)));
  p->mat->c = xmalloc(sizeof(*(p->mat->c)));
  type = get_value(get_node("type", nd));
  fill_pos(&(p->pos), get_node("position", nd));
  fill_pos(&(p->rot), get_node("rotation", nd));
  fill_color(&(p->mat->c), get_node("material/color", nd));
  p->mat->q_shi = to_double(get_value(get_node("material/shininess", nd)));
  sh[get_type(type, cores)](sc, p, nd);
}
