/*
** print_special_figs.c for print_special_figs in /home/jordan/Projets/Epitech/rt/verbose_mode
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Sun Jun  3 02:59:19 2012 jordan vanwalleghem
** Last update Sun Jun  3 05:14:53 2012 jordan vanwalleghem
*/

#include "my.h"
#include "object.h"

void	tore_figs(t_object *type)
{
  my_putstr("D'un tore de rayon X : ");
  my_putdouble(((t_tore *)(type->son))->radius[0]);
  my_putstr(" Y : ");
  my_putdouble(((t_tore *)(type->son))->radius[1]);
}

void	cube_troue_figs(t_object *type)
{
  my_putstr("D'un cube troue de rayon : ");
  my_putdouble(((t_cubetroue *)(type->son))->radius);
  my_putstr(" et de taille ");
  my_putdouble(((t_cubetroue *)(type->son))->size);
}

void	hyperbo_figs(t_object *type)
{
  my_putstr("Un hyperboloide de parametre A : ");
  my_putdouble(((t_hyperboloide *)(type->son))->a);
  my_putstr(" B : ");
  my_putdouble(((t_hyperboloide *)(type->son))->b);
  my_putstr(" C : ");
  my_putdouble(((t_hyperboloide *)(type->son))->c);
}

void	moebius_figs()
{
  my_putstr("D'un ruban de Moebius Kikoo");
}
