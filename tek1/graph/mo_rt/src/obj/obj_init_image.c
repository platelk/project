/*
** obj_init_image.c for obj in /home/vink/projet/graph/rt/src/obj
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Wed May 16 08:12:49 2012 kevin platel
** Last update Wed May 30 16:04:52 2012 ronan guiho
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

int	obj_get_perlin_ceil(t_xtree *tree)
{
  char	*tmp;

  if (tree)
    {
      tmp = xml_find_attr(tree->attr, "CEIL");
      if (my_strcmp(tmp, "ON") == 0)
	return (1);
      if (my_strcmp(tmp, "OFF") == 0)
	return (0);
      return (0);
    }
  return (0);
}

int	obj_get_perlin_apply(t_xtree *tree)
{
  char	*tmp;

  if (tree)
    {
      tmp = xml_find_attr(tree->attr, "APPLY");
      if (my_strcmp(tmp, "BUMP") == 0)
	return (APP_BUMP);
      if (my_strcmp(tmp, "TEXTURE") == 0)
	return (APP_TEXT);
      if (my_strcmp(tmp, "BUMP_TEXTURE") == 0)
	return (APP_BUMP_TEXT);
      return (1);
    }
  return (1);
}

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
  if (new && tmp && new->image_bump)
    {
      tmp != NULL && new->image_bump ? (new->image_bump->freq =
				   my_getdouble(xml_find_attr(tmp->attr, "FREQUENCE"))) :
       1.0;
      tmp != NULL && new->image_bump ? (new->image_bump->relief =
				   my_getdouble(xml_find_attr(tmp->attr, "RELIEF"))) :
       1.0;
      if (my_strcmp(xml_find_attr(tmp->attr, "TYPE"), "NORMAL") == 0)
	new->image_bump->type = B_NORMAL;
      else if (my_strcmp(xml_find_attr(tmp->attr, "TYPE"), "DISPLACEMENT") == 0)
	new->image_bump->type = B_DISPLACEMENT;
      else if (my_strcmp(xml_find_attr(tmp->attr, "TYPE"), "BUMP") == 0)
	new->image_bump->type = B_BUMP;
      else
	new->image_bump->type = B_NONE;
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
			       my_getdouble(xml_find_attr(tmp->attr, "FREQUENCE"))) :
    1.0;
  new = obj_init_bump(new, tree, mlx_ptr);
  tmp = xml_find_in_tree(tree->sun, STRING_PERL);
  if (tmp != NULL)
    {
      new->perlin = malloc(sizeof(*(new->perlin)));
      if (new->perlin != NULL)
	{
	  new->perlin->apply = obj_get_perlin_apply(tmp);
	  new->perlin->effect = obj_get_perlin_type(tmp);
	  new->perlin->freq = my_getdouble(xml_find_attr(tmp->attr, "FREQUENCE"));
	  new->perlin->persistance = my_getdouble(xml_find_attr(tmp->attr, "PERSISTANCE"));
	  new->perlin->nbr_octave = my_getdouble(xml_find_attr(tmp->attr, "OCTAVE"));
	  new->perlin->relief = my_getdouble(xml_find_attr(tmp->attr, "RELIEF"));
	  new->perlin->ceil = obj_get_perlin_ceil(tmp);
	  new->perlin->begin = init_color(xml_find_attr(tmp->attr, "COLOR1"));
	  new->perlin->end = init_color(xml_find_attr(tmp->attr, "COLOR2"));
	  create_perlin_noise(new->perlin);
	}
    }
  else
    new->perlin = NULL;
  return (new);
}
