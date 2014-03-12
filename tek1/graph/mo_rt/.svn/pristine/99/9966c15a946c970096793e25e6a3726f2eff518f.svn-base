/*
** obj_init_image.c for obj in /home/vink/projet/graph/rt/src/obj
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Wed May 16 08:12:49 2012 kevin platel
** Last update Sun May 27 11:46:34 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#include	"global.h"
#include	"init.h"
#include	"raytracer.h"
#include	"xml_chr.h"
#include	"xml_tree.h"
#include	"object.h"
#include	"my.h"
#include	"obj_create.h"
#include	"obj_print.h"
#include	"perlin_noise.h"

int	obj_get_perlin_type(t_xtree *tree)
{
  char	*tmp;

  if (tree)
    {
      tmp = xml_find_attr(tree->attr, "TYPE");
      if (my_strcmp(tmp, "WOOD") == 0)
	return (WOOD);
      if (my_strcmp(tmp, "MARBEL") == 0)
	return (MARBLE);
      return (NONE);
    }
  return (NONE);
}

t_object	*obj_init_bump(t_object *new, t_xtree *tree, void *mlx_ptr)
{
  t_xtree	*tmp;

  tmp = xml_find_in_tree(tree->sun, STRING_BUMP);
  tmp != NULL && new ? (new->image_bump = init_image(mlx_ptr, tmp->content, 0, 0))
    : (new->image_bump = NULL);
  if (new && tmp && new->image)
    {
      if (my_strcmp(xml_find_attr(tmp->attr, "TYPE"), "NORMAL") == 0)
	new->image->type = B_NORMAL;
      else if (my_strcmp(xml_find_attr(tmp->attr, "TYPE"), "DISPLACEMENT") == 0)
	new->image->type = B_DISPLACEMENT;
      else if (my_strcmp(xml_find_attr(tmp->attr, "TYPE"), "BUMP") == 0)
	new->image->type = B_BUMP;
      else
	new->image->type = B_NONE;
    }
  return (new);
}

t_object	*obj_init_image(t_xtree *tree, t_object *new, void *mlx_ptr)
{
  t_xtree	*tmp;

  tmp = xml_find_in_tree(tree->sun, STRING_COL);
  tmp != NULL ? (new->color = init_color(tmp->content)) : (new->color = NULL);
  tmp = xml_find_in_tree(tree->sun, STRING_TEX);
  tmp != NULL ? (new->image = init_image(mlx_ptr, tmp->content, 0, 0))
    : (new->image = NULL);
  tmp != NULL && new->image ? (new->image->freq =
			       my_getdouble(xml_find_attr(tmp->attr, "FREQUENCE")) ) :
    0.0;
  new = obj_init_bump(new, tree, mlx_ptr);
  tmp = xml_find_in_tree(tree->sun, STRING_PERL);
  if (tmp != NULL)
    {
      new->perlin = malloc(sizeof(*(new->perlin)));
      if (new->perlin != NULL)
	{
	  new->perlin->effect = obj_get_perlin_type(tmp);
	  new->perlin->persistance = my_getdouble(xml_find_attr(tmp->attr, "PERSISTANCE"));
	  new->perlin->nbr_octave = my_getdouble(xml_find_attr(tmp->attr, "OCTAVE"));
	  new->perlin->ceil = 0;
	  new->perlin->begin = init_color(xml_find_attr(tmp->attr, "COLOR1"));
	  new->perlin->end = init_color(xml_find_attr(tmp->attr, "COLOR2"));
	  create_perlin_noise(new->perlin);
	}
    }
  else
    new->perlin = NULL;
  return (new);
}
