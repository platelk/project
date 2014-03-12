/*
** obj_create_list_light.c for obj in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:28:01 2012 kevin platel
** Last update Sun Jun  3 16:28:01 2012 kevin platel
*/

#include	<stdlib.h>

#include	"init.h"
#include	"global.h"
#include	"xml_tree.h"
#include	"xml_chr.h"
#include	"obj_create.h"
#include	"camera.h"
#include	"light.h"
#include	"my.h"

void		obj_bzero_light_dim(double *tab)
{
  tab[X] = 0.0;
  tab[Y] = 0.0;
  tab[Z] = 0.0;
}

t_light	*obj_init_light_dimension(t_xtree *tmp, t_light *new, t_xtree *tree)
{
  if ((tmp = xml_find_in_tree(tree->sun, STRING_LOC, 0)) != NULL)
    {
      new->location[X] = my_getnbr(xml_find_attr(tmp->attr, STRING_X));
      new->location[Y] = my_getnbr(xml_find_attr(tmp->attr, STRING_Y));
      new->location[Z] = my_getnbr(xml_find_attr(tmp->attr, STRING_Z));
    }
  else
    obj_bzero_light_dim(new->location);
  return (new);
}

t_light	*obj_create_light(t_xtree *tree, t_light *light)
{
  t_light	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (!new)
    return (NULL);
  new = obj_init_light_dimension(tree, new, tree);
  tmp = xml_find_in_tree(tree->sun, "color", 0);
  if (!tmp)
    new->color = init_color("00");
  else
    new->color = init_color(tmp->content);
  tmp = xml_find_in_tree(tree->sun, "intensity", 0);
  if (!tmp)
    new->intensity = 0.000;
  else
    new->intensity = my_getdouble(tmp->content);
  new->type = (t_type) obj_get_light_type
    (xml_find_attr(tree->attr, STRING_TYPE));
  new->next = NULL;
  if (light)
    light->next = new;
  return (new);
}

t_light	*obj_create_list_light(t_xtree *tree)
{
  t_light	*light;
  t_light	*tmp;

  tree = xml_find_in_tree(tree, "window/scene/lights/light", 0);
  if (!tree)
    return (NULL);
  light = NULL;
  tmp = light;
  while (tree)
    {
      tmp = obj_create_light(tree, tmp);
      if (light == NULL)
	light = tmp;
      tree = tree->next;
    }
  return (light);
}
