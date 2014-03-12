/*
** get_data_champ.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jan 27 15:28:29 2012 ronan guiho
** Last update Sun Mar 25 16:40:15 2012 alexandre deceneux
*/

#include <stdlib.h>

#include "corewar.h"
#include "data_champ.h"

int		get_data_champ(t_data_champ *ptr, char **av, int indice)
{
  ptr->name = my_strdup(av[indice++]);
  if (av && av[indice] && *(av[indice]) == '-')
    {
      if (av && av[indice + 1] && av[indice][1] == 'n' &&
	  !is_number(av[indice + 1]))
	ptr->id = my_getnbr(av[++indice]);
      else if (av && av[indice][0] && av[indice][1] == 'a' && av[indice + 1]
	       && !is_number(av[indice + 1]))
	ptr->addr = my_getnbr(av[++indice]);
      else
	return (-1);
      if (av && av[indice + 1] && *av[indice + 1] == '-')
	{
	  if (av[indice + 1][1] == 'n')
	    ptr->id = my_getnbr(av[indice + 2]);
	  else if (av[indice + 1][1] == 'a')
	    ptr->addr = my_getnbr(av[indice + 2]);
	  ptr->name = my_strdup(av[indice + 3]);
	  indice = indice + 3;
	}
      else
	ptr->name = my_strdup(av[++indice]);
      indice++;
    }
   return (indice);
}
