/*
** obj_type.c for obj in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:29:34 2012 kevin platel
** Last update Sun Jun  3 16:29:37 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"obj_create.h"
#include	"object.h"
#include	"my.h"
#include	"inter.h"

int	obj_get_type_error(char *name)
{
  write(2, "Error : ", 8);
  write(2, name, my_strlen(name));
  write(2, " unrecognized.\n", 15);
  return (0);
}

int	obj_get_type(char *name)
{
  char	*tab[NB_TYPE + 1];
  int	i;

  tab[SPHERE] = STRING_SPH;
  tab[PLAN] = STRING_PLA;
  tab[CYL] = STRING_CYL;
  tab[CON] = STRING_CON;
  tab[TORE] = STRING_TOR;
  tab[CUBE_TROUE] = STRING_CUBET;
  tab[PARABOLOIDE] = STRING_PARA;
  tab[HYPERBOLOIDE] = STRING_HYPER;
  tab[MOEBIUS] = STRING_MOEB;
  tab[CUBE] = STRING_CUBE;
  tab[TRIANGLE] = STRING_TRIA;
  tab[BLENDER] = STRING_BLEND;
  tab[NB_TYPE] = NULL;
  i = 0;
  while (tab[i])
    {
      if (my_strcmp(tab[i], name) == 0)
	return (i);
      i++;
    }
  obj_get_type_error(name);
  return (-1);
}

int	obj_get_light_type(char *name)
{
  char	*tab[3 + 1];
  int	i;

  tab[AMBIENT] = "ambient";
  tab[PARALLELE] = "parallele";
  tab[DIFFUSE] = "diffuse";
  tab[3] = NULL;
  i = 0;
  while (tab[i])
    {
      if (my_strcmp(tab[i], name) == 0)
	return (i);
      i++;
    }
  return (-1);
}

t_inter	obj_get_inter_fct(int i)
{
  t_inter	tab[NB_TYPE + 1];

  tab[SPHERE] = &inter_sphere;
  tab[PLAN] = &inter_plan;
  tab[CYL] = &inter_cylindre;
  tab[CON] = &inter_cone;
  tab[TORE] = &inter_tore;
  tab[CUBE_TROUE] = &inter_cubetroue;
  tab[PARABOLOIDE] = &inter_paraboloide;
  tab[HYPERBOLOIDE] = &inter_hyperboloide;
  tab[MOEBIUS] = &inter_moebius;
  tab[CUBE] = &inter_plan;
  tab[TRIANGLE] = &inter_triangle;
  tab[BLENDER] = &inter_blender;
  tab[NB_TYPE] = NULL;
  if (i > NB_TYPE || i < 0)
    return (NULL);
  return (tab[i]);
}
