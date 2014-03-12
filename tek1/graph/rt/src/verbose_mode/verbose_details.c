/*
** verbose_details.c for verbose_details in /home/jordan/Projets/Epitech/rt/verbose_mode
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Thu May 31 17:08:43 2012 jordan vanwalleghem
** Last update Sun Jun  3 17:34:23 2012 alexis leprovost
*/

#include "my.h"
#include "object.h"

void	type_double(t_obj_type type, void *son)
{
  if (type == CUBE)
    {
      my_putstr("Un cube de taille : ");
      my_putdouble(((t_cube *)son)->size);
    }
  if (type == PARABOLOIDE)
    {
      my_putstr("Un paraboloid de rayon : ");
      my_putdouble(((t_paraboloide *)son)->radius);
    }
  if (type == SPHERE)
    {
      my_putstr("Une sphere de rayon : ");
      my_putdouble(((t_sphere *)son)->radius);
    }
  if (type == CYL)
    {
      my_putstr("Un cylindre de rayon : ");
      my_putdouble(((t_cylindre *)son)->radius);
    }
}
