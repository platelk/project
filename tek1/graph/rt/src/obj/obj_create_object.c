/*
** obj_create_object.c for obj in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:28:22 2012 kevin platel
** Last update Sun Jun  3 16:28:24 2012 kevin platel
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
#include	"obj_bzero_dim.h"

t_object	*obj_effect(t_object *new, t_xtree *tmp)
{
  tmp = xml_find_in_tree(tmp->sun, STRING_EFFECT, 0);
  if (!tmp)
    obj_effect_bzero(new->effect);
  else
    {
      new->effect[REFLECTION] = my_getdouble(xml_find_attr
					     (tmp->attr, STRING_REFL));
      new->effect[BRIGHTNESS] = my_getdouble(xml_find_attr
					     (tmp->attr, STRING_BRIG));
      new->effect[TRANSPARENCY] = my_getdouble
	(xml_find_attr(tmp->attr, STRING_TRA));
      new->effect[PHONG] = ABS
	(my_getdouble(xml_find_attr(tmp->attr, STRING_PHONG)));
      if (new->effect[PHONG] == 0.0F)
	new->effect[PHONG] = (1.0F / QUATRO
			      (new->effect[BRIGHTNESS] + 0.000001F));
    }
  return (new);
}

t_object        *obj_init_dimension_n(t_xtree *tmp,
				      t_object *new, t_xtree *tree)
{
  if ((tmp = xml_find_in_tree(tree->sun, STRING_PER, 0)) != NULL)
    {
      new->perturbation[X] = my_getdouble(xml_find_attr(tmp->attr, STRING_X));
      new->perturbation[Y] = my_getdouble(xml_find_attr(tmp->attr, STRING_Y));
      new->perturbation[Z] = my_getdouble(xml_find_attr(tmp->attr, STRING_Z));
    }
  else
    obj_bzero_dim(new->perturbation);
  if ((tmp = xml_find_in_tree(tree->sun, STRING_MATERIAL, 0)) != NULL)
    {
      new->material = my_getdouble(tmp->content);
      new->material = !new->material ? 1.0F : new->material;
    }
  else
    new->material = 1.0F;
  return (new);
}

t_object	*obj_init_dimension(t_xtree *tmp, t_object *new, t_xtree *tree)
{
  if ((tmp = xml_find_in_tree(tree->sun, STRING_LOC, 0)) != NULL)
    {
      new->position[X] = my_getdouble(xml_find_attr(tmp->attr, STRING_X));
      new->position[Y] = my_getdouble(xml_find_attr(tmp->attr, STRING_Y));
      new->position[Z] = my_getdouble(xml_find_attr(tmp->attr, STRING_Z));
    }
  else
    obj_bzero_dim(new->position);
  if ((tmp = xml_find_in_tree(tree->sun, STRING_ROT, 0)) != NULL)
    {
      new->rotation[X] = my_getdouble(xml_find_attr(tmp->attr, STRING_X));
      new->rotation[Y] = my_getdouble(xml_find_attr(tmp->attr, STRING_Y));
      new->rotation[Z] = my_getdouble(xml_find_attr(tmp->attr, STRING_Z));
    }
  else
    obj_bzero_dim(new->rotation);
  return (obj_init_dimension_n(tmp, new, tree));
}

t_object	*obj_add_object(t_xtree *tree, t_object *obj, t_object *o,
				void *mlx_ptr)
{
  t_object	*new;

  new = NULL;
  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new = obj_init_dimension(tree, new, tree);
  if ((int) (new->type = (t_type) obj_get_type(tree->name)) < 0)
    return (NULL);
  obj_bzero_dim(new->box_size);
  obj_bzero_dim(new->box_pos);
  new->limit = obj_create_limit(tree);
  new = obj_init_image(tree, new, mlx_ptr);
  new->inter = obj_get_inter_fct(new->type);
  new->son = obj_create_son(new->type, tree);
  new = obj_effect(new, tree);
  new->attr = tree->attr;
  new->limit = obj_create_limit(tree);
  new->inhibitor = o;
  new->next = NULL;
  new->prev = obj;
  if (obj)
    obj->next = new;
  return (new);
}

t_object	*obj_create_list_object(t_xtree *tree, char *type_get,
					t_object *o, void *mlx_ptr)
{
  t_object	*obj;
  t_object	*tmp;

  tree = xml_find_in_tree(tree, STRING_OBJ, 0);
  if (tree == NULL)
    return (NULL);
  tree = tree->sun;
  if (tree == NULL)
    return (NULL);
  obj = NULL;
  tmp = obj;
  while (tree)
    {
      if (my_strcmp(xml_find_attr(tree->attr, STRING_TYPE), type_get) == 0
	  || (xml_find_attr(tree->attr, STRING_TYPE) == NULL &&
	      my_strcmp(type_get, STRING_NORM) == 0))
	{
	  tmp = obj_add_object(tree, tmp, o, mlx_ptr);
	  if (obj == NULL)
	    obj = tmp;
	}
      tree = tree->next;
    }
  return (obj);
}
