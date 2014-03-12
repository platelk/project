/*
** limites_object_calc.c for rt in /home/phalip_z//exos/projets/RT/src/limited_objects
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Mon May 14 16:53:39 2012 zoe phalippou
** Last update Sun Jun  3 11:31:10 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"raytracer.h"
#include	"camera.h"
#include        "object.h"
#include	"detail.h"
#include	"calc.h"
#include	"utils.h"
#include	"inter.h"
#include	"objects_neg.h"

static ptr_f_inhib	*create_ptr_func_inhib(ptr_f_inhib *indice)
{
  indice[0] = &inter_indice_sphere;
  indice[1] = &inter_indice_sphere;
  indice[2] = &inter_indice_cylindre;
  indice[3] = &inter_indice_cone;
  indice[4] = &inter_indice_cylindre;
  indice[5] = &inter_indice_cylindre;
  indice[6] = &inter_indice_paraboloide;
  indice[7] = &inter_indice_hyperboloide;
  indice[8] = NULL;
  return (indice);
}

static void k_in_order(double *k)
{
  int	i;
  int	flag;

  flag = 1;
  while (flag)
    {
      flag = 0;
      i = 0;
      if (k[i] && k[i + 1])
	if (k[i] > k[i + 1])
	  {
	    k[i] = k[i + 1];
	    k[i + 1] = k[i];
	    flag = 1;
	  }
    }
}

static int	change_k(double *k_inib, double *k,
			 double *indice_inib, int flag)
{
  if (indice_inib[DELTA] >= 0.0F)
    {
      calc_k(indice_inib, k_inib);
      k_in_order(k_inib);
      if (k_inib[0] >= 0.000 && k_inib[1] >= 0.000
	  && k_inib[0] < k[0] && k_inib[1] > k[0] && k_inib[1] < k[1])
	{
	  k[0] = k_inib[1];
	  flag = 0;
	}
      if (k_inib[0] >= 0.000 && k_inib[1] >= 0.000
	  && k_inib[0] < k[0] && k_inib[1] > k[0])
	k[0] = -1.000;
      else if ((k_inib[0] >= 0.000 && k_inib[1] >= 0.000) && k_inib[0] <= k[0]
	       && k_inib[1] > k[0] && k_inib[1] > k[1])
	k[0] = -1.000;
      else if ((k_inib[0] && !k_inib[1]))
	k[0] = k_inib[0];
    }
  return (flag);
}

void	obj_inhibitor(double *k, t_object *obj, t_camera *camera,
		      double *vector)
{
  double	indice_inib[NB_INDICE];
  double	k_inib[4];
  t_object	*tmp;
  ptr_f_inhib	inter_indice[9];
  int		flag;

  flag = 0;
  k_in_order(k);
  create_ptr_func_inhib(inter_indice);
  while (!flag)
    {
      flag = 1;
      tmp = obj->inhibitor;
      while (tmp)
	{
	  inter_indice[tmp->type](camera, tmp, vector, indice_inib);
	  flag = change_k(k_inib, k, indice_inib, flag);
	  tmp = tmp->next;
	}
    }
  k[1] = -1.0;
}
