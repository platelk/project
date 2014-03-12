/*
** define_r.c for define_r in /home/platel_k/projet/bistro/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Nov  8 17:45:40 2011 kevin platel
** Last update Wed Nov  9 11:20:13 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

t_list	*define_r(t_list *result, t_list *r_sub, t_list *nb_cpy, char *op)
{
  t_list	*r;

  r = NULL;
  if (result != NULL)
    r = r_sub;
  else
    r = nb_cpy;
  if (r->cha == op[3])
    r = del_one_in_list(&r);
  return (r);
}
