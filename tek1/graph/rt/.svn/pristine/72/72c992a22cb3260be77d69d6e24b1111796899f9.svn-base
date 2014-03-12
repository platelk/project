/*
** obj_create_sun.c for obj in /home/vink/projet/graph/rt/src/obj
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May  8 15:11:36 2012 kevin platel
** Last update Sun May 27 17:49:49 2012 kevin platel
*/

#include	<stdlib.h>

#include	"object.h"
#include	"obj_create.h"
#include	"xml_tree.h"
#include	"xml_chr.h"
#include	"my.h"

void		*obj_create_pla(t_xtree *tree)
{
  t_plan	*new;

  tree = tree;
  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  return (new);
}

void		*obj_create_cube(t_xtree *tree)
{
  t_xtree	*tmp;
  t_cube	*new;

  tree = tree;
  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "size");
  if (tmp != NULL)
    new->size = my_getdouble(tmp->content);
  else
    new->size = 0.0F;
  return (new);
}

void		*obj_create_tore(t_xtree *tree)
{
  t_tore	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius");
  if (tmp != NULL)
    {
      new->radius[0] = my_getdouble(xml_find_attr(tmp->attr, "MIN"));
      new->radius[1] = my_getdouble(xml_find_attr(tmp->attr, "MAX"));
    }
  else
    {
      new->radius[0] = 0.0F;
      new->radius[1] = 0.0F;
    }
  return (new);
}

void		*obj_create_cubetroue(t_xtree *tree)
{
  t_cubetroue	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius");
  if (tmp != NULL)
    new->radius = my_getdouble(tmp->content);
  else
    new->radius = 0.0F;
  tmp = xml_find_in_tree(tree, "size");
  if (tmp != NULL)
    new->size = my_getdouble(tmp->content);
  else
    new->size = 0.0F;
  return (new);
}

void		*obj_create_con(t_xtree *tree)
{
  t_cone	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius");
  if (tmp)
    new->angle = my_getdouble(tmp->content);
  else
    new->angle = 0.0F;
  return (new);
}

void	*obj_create_cyl(t_xtree *tree)
{
  t_cylindre	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius");
  if (tmp)
    new->radius = my_getdouble(tmp->content);
  else
    new->radius = 0.0F;
  return (new);
}

void	*obj_create_sph(t_xtree *tree)
{
  t_sphere	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius");
  if (tmp)
    new->radius = my_getdouble(tmp->content);
  else
    new->radius = 0.0F;
  return (new);
}

void	*obj_create_paraboloide(t_xtree *tree)
{
  t_paraboloide	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "radius");
  if (tmp)
    new->radius = my_getdouble(tmp->content);
  else
    new->radius = 0.0F;
  return (new);
}

void	*obj_create_hyperboloide(t_xtree *tree)
{
  t_hyperboloide	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "constante");
  if (tmp)
    {
      new->a = my_getdouble(xml_find_attr(tmp->attr, "A"));
      new->b = my_getdouble(xml_find_attr(tmp->attr, "B"));
      new->c = my_getdouble(xml_find_attr(tmp->attr, "C"));
    }
  else
    {
      new->a = 0.0F;
      new->b = 0.0F;
      new->c = 0.0F;
    }
  return (new);
}

void		*obj_create_moebius(t_xtree *tree)
{
  t_mobius	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree->sun, "size");
  if (tmp)
    {
      new->a = my_getdouble(xml_find_attr(tmp->attr, "A"));
      new->b = my_getdouble(xml_find_attr(tmp->attr, "B"));
      new->c = my_getdouble(xml_find_attr(tmp->attr, "C"));
    }
  return (new);
}

void	*obj_create_son(int type, t_xtree *tree)
{
  t_create	tab[NB_TYPE + 1];

  tab[SPHERE] = &obj_create_sph;
  tab[PLAN] = &obj_create_pla;
  tab[CYL] = &obj_create_cyl;
  tab[CON] = &obj_create_con;
  tab[TORE] = &obj_create_tore;
  tab[CUBE_TROUE] = &obj_create_cubetroue;
  tab[PARABOLOIDE] = &obj_create_paraboloide;
  tab[HYPERBOLOIDE] = &obj_create_hyperboloide;
  tab[MOEBIUS] = &obj_create_moebius;
  tab[CUBE] = &obj_create_cube;
  tab[NB_TYPE] = NULL;
  if (type > NB_TYPE || type < 0)
    return (NULL);
  return (tab[type](tree));
}
