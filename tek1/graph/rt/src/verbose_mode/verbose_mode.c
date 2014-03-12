/*
** verbose_mode.c for verbose_mode in /home/jordan/Projets/Epitech/rt/verbose_mode
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Thu May 31 15:00:39 2012 jordan vanwalleghem
** Last update Sun Jun  3 19:48:16 2012 alexis leprovost
*/

#include "my.h"
#include "object.h"
#include "verbose_mode.h"
#include "print_win_attrib.h"
#include "print_special_figs.h"
#include "print_scene_attrib.h"
#include "type_double.h"

void	determ_type(t_object *type)
{
  if (type->type == SPHERE || type->type == CYL || type->type == CON ||
      type->type == PARABOLOIDE || type->type == CUBE)
    type_double(type->type, type->son);
  else if (type->type == PLAN)
    my_putstr("d'un plan");
  else if (type->type == TORE)
    tore_figs(type);
  else if (type->type == CUBE_TROUE)
    cube_troue_figs(type);
  else if (type->type == HYPERBOLOIDE)
    hyperbo_figs(type);
  else if (type->type == MOEBIUS)
    moebius_figs();
  my_putstr("\n");
}

void	print_attrib(t_object *ptr)
{
  my_putstr("En position X : ");
  my_putnbr(ptr->position[0]);
  my_putstr(" Y : ");
  my_putnbr(ptr->position[1]);
  my_putstr(" Z : ");
  my_putnbr(ptr->position[2]);
  my_putstr("\n");
  my_putstr("Avec une rotation de X : ");
  my_putnbr(ptr->rotation[0]);
  my_putstr(" Y : ");
  my_putnbr(ptr->rotation[1]);
  my_putstr(" Z : ");
  my_putnbr(ptr->rotation[2]);
  my_putstr("\n");
}

void	object_details(t_object *ptr)
{
  my_putstr("La scene est composé ");
  while (ptr != NULL)
    {
      determ_type(ptr);
      print_attrib(ptr);
      ptr = ptr->next;
      if (ptr != NULL)
	my_putstr("\nAinsi que ");
    }
}

void	verbose_mode(t_global *global)
{
  if (global == NULL)
    my_putstr("Il n'y a aucune scene\n");
  else
    {
      print_win_atrib(global->window);
      print_scene_atrib(global->scene);
      my_putstr("\n\t[Fin de la description]\n\n");
    }
}
