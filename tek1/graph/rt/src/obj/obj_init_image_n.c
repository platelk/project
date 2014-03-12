/*
** obj_init_image_n.c for obj_init_image_n in /home/jordan/Projets/debug_rt/rt/src/obj
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Sat Jun  2 11:40:35 2012 jordan vanwalleghem
** Last update Sun Jun  3 14:32:19 2012 kevin platel
*/

#include        <stdlib.h>
#include        <stdio.h>
#include        <unistd.h>

#include        "global.h"
#include        "init.h"
#include        "raytracer.h"
#include        "xml_chr.h"
#include        "xml_tree.h"
#include        "object.h"
#include        "my.h"
#include        "obj_create.h"
#include        "obj_print.h"
#include        "perlin_noise.h"
#include        "procedural.h"

int     obj_get_perlin_ceil(t_xtree *tree)
{
  char  *tmp;

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

int     obj_get_perlin_apply(t_xtree *tree)
{
  char  *tmp;

  if (tree)
    {
      tmp = xml_find_attr(tree->attr, "APPLY");
      if (my_strcmp(tmp, "BUMP") == 0)
        return (APP_BUMP);
      if (my_strcmp(tmp, "TEXTURE") == 0)
        return (APP_TEXT);
      if (my_strcmp(tmp, "BUMP_TEXTURE") == 0)
        return (APP_BUMP_TEXT);
      return (-1);
    }
  return (-1);
}

int     obj_get_perlin_type(t_xtree *tree)
{
  char  *tmp;

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

t_object        *obj_init_bump(t_object *new, t_xtree *tree, void *mlx_ptr)
{
  t_xtree       *tmp;

  tmp = xml_find_in_tree(tree->sun, STRING_BUMP, 0);
  tmp != NULL && new ? (new->image_bump =
                        init_image(mlx_ptr, tmp->content, 0, 0))
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
      else if (my_strcmp(xml_find_attr
                         (tmp->attr, "TYPE"), "DISPLACEMENT") == 0)
        new->image_bump->type = B_DISPLACEMENT;
      else if (my_strcmp(xml_find_attr(tmp->attr, "TYPE"), "BUMP") == 0)
        new->image_bump->type = B_BUMP;
      else
        new->image_bump->type = B_NONE;
    }
  return (new);
}
