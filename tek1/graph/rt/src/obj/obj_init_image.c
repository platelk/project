/*
** obj_init_image.c for obj in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:29:16 2012 kevin platel
** Last update Sun Jun  3 16:29:17 2012 kevin platel
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
#include	"procedural.h"
#include	"obj_init_image.h"

static int	fill_default(t_xtree *tmp, t_image *i)
{
  if (i == NULL || tmp == NULL)
    return (EXIT_FAILURE);
  i->freq = (tmp != NULL ? my_getdouble
	     (xml_find_attr(tmp->attr, "FREQUENCE")) : 1.0F);
  i->type = NONE;
  i->freq = 1.0F;
  i->relief = 0.0F;
  i->type_texture = 0;
  i->cut_texture = NULL;
  return (EXIT_SUCCESS);
}

t_image		*fct_init_image(t_xtree *tree, t_image *i, void *mlx_ptr)
{
  t_xtree	*tmp;
  char	*str;

  tmp = xml_find_in_tree(tree->sun, STRING_TEX, 0);
  tmp != NULL ? (i = init_image(mlx_ptr, tmp->content, 0, 0))
    : (i = NULL);
  if (i)
    fill_default(tmp, i);
  if (tmp)
    str = xml_find_attr(tmp->attr, "TYPE");
  if (tmp && i && str)
    {
      if (!(i->cut_texture = malloc(sizeof(*(i->cut_texture)))))
	return (NULL);
      i->type_texture = ((my_strcmp(str, "cut") == 0) ? (1) : (0));
      i->cut_texture->tcolor = init_color(xml_find_attr(tmp->attr, "COLOR"));
      i->cut_texture->interval =
	my_getnbr(xml_find_attr(tmp->attr, "INTERVAL"));
      i->cut_texture->flag =
	(my_strcmp(xml_find_attr(tmp->attr, "KEEP"), "yes") == 0 ? 1 : 0);
    }
  return (i);
}

t_object	*obj_init_procedural(t_object *new, t_xtree *tree)
{
  t_xtree	*tmp;

  tmp = NULL;
  tmp = xml_find_in_tree(tree->sun, "procedural", 0);
  if (tmp)
    {
      new->procedural = malloc(sizeof(*new->procedural));
      if (new->procedural == NULL)
	return (new);
      new->procedural->type =
	(my_strcmp(xml_find_attr(tmp->attr, "TYPE"), "damier") == 0) ? 1 : 0;
      new->procedural->c1 = init_color(xml_find_attr(tmp->attr, "COLOR1"));
      new->procedural->c2 = init_color(xml_find_attr(tmp->attr, "COLOR2"));
      new->procedural->size = my_getnbr(xml_find_attr(tmp->attr, "SIZE"));
    }
  else
    new->procedural = NULL;
  return (new);
}

void		obj_init_perli(t_object *new, t_xtree *tmp)
{
  new->perlin->apply = obj_get_perlin_apply(tmp);
  new->perlin->effect = obj_get_perlin_type(tmp);
  new->perlin->freq = my_getdouble(xml_find_attr(tmp->attr, "FREQUENCE"));
  new->perlin->persistance =
    my_getdouble(xml_find_attr(tmp->attr, "PERSISTANCE"));
  new->perlin->nbr_octave = my_getdouble(xml_find_attr(tmp->attr, "OCTAVE"));
  new->perlin->relief = my_getdouble(xml_find_attr(tmp->attr, "RELIEF"));
  new->perlin->ceil = obj_get_perlin_ceil(tmp);
  new->perlin->begin = init_color(xml_find_attr(tmp->attr, "COLOR1"));
  new->perlin->end = init_color(xml_find_attr(tmp->attr, "COLOR2"));
  create_perlin_noise(new->perlin);
}

t_object	*obj_init_image(t_xtree *tree, t_object *new, void *mlx_ptr)
{
  t_xtree	*tmp;

  new->image = fct_init_image(tree, new->image, mlx_ptr);
  tmp = xml_find_in_tree(tree->sun, STRING_COL, 0);
  tmp != NULL ? (new->color = init_color(tmp->content)) : (new->color = NULL);
  new = obj_init_procedural(new, tree);
  new = obj_init_bump(new, tree, mlx_ptr);
  new = obj_init_procedural(new, tree);
  tmp = xml_find_in_tree(tree->sun, STRING_PERL, 0);
  if (tmp != NULL)
    {
      if ((new->perlin = malloc(sizeof(*(new->perlin))))  != NULL)
	obj_init_perli(new, tmp);
      else
	new->perlin = NULL;
    }
  else
    new->perlin = NULL;
  return (new);
}
