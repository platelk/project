/*
** obj_create_sun.c for ovj in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:28:47 2012 kevin platel
** Last update Sun Jun  3 16:28:48 2012 kevin platel
*/

#include	<stdlib.h>

#include	"object.h"
#include	"obj_create.h"
#include	"xml_tree.h"
#include	"xml_chr.h"
#include	"my.h"
#include	"obj_create_sun.h"

void	*obj_create_blender(t_xtree *tree)
{
  t_blender	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree, "import", 0);
  if (tmp)
    new->path = tmp->content;
  else
    new->path = NULL;
  return (new);
}

void		*obj_create_moebius(t_xtree *tree)
{
  t_mobius	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = xml_find_in_tree(tree->sun, "size", 0);
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
  tab[CUBE] = NULL;
  tab[TRIANGLE] = NULL;
  tab[BLENDER] = &obj_create_blender;
  tab[NB_TYPE] = NULL;
  if (type > NB_TYPE || type < 0)
    return (NULL);
  return (tab[type](tree));
}
