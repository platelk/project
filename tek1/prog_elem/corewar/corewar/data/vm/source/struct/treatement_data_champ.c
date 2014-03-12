/*
** treatement_data_champ.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jan 27 14:44:16 2012 ronan guiho
** Last update Fri Mar 23 15:47:12 2012 kevin platel
*/

#include <stdlib.h>

#include "param.h"
#include "corewar.h"
#include "data_champ.h"

t_data_champ	*treatment_data_champ(int ac, char **av, t_param *param)
{
  int		indice;
  t_data_champ	*data;

  data = NULL;
  indice = 1;
  if (check_args(ac, av))
      return (NULL);
  while (indice < ac)
    {
      create_struct_param(av, &indice, param);
      if (indice < ac && av[indice] != NULL)
	if ((indice = create_list_data_champ(&data, av, indice)) == -1)
	  {
	    my_printf("Missing number after an option\n");
	    return (NULL);
	  }
    }
  return (data);
}
