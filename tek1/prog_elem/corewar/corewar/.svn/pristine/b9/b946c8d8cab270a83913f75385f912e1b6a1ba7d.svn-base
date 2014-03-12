/*
** create_struct_param.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jan 29 13:31:32 2012 ronan guiho
** Last update Sun Mar 18 13:48:07 2012 alexis leprovost
*/

#include <stdlib.h>

#include "param.h"
#include "corewar.h"

int	option(char **av, int *indice, int *option)
{
  int	i;

  i = -1;
  *indice = *indice + 1;
  if (av[*indice] != NULL)
    {
      while (av[*indice][++i])
	if (isnum(av[*indice][i]) && av[*indice][i] != '-')
	  return (1);
      *option= my_getnbr(av[*indice]);
      *indice = *indice + 1;
      return (0);
    }
  return (1);
}

int		create_struct_param(char **av, int *indice, t_param *param)
{
  if (av[*indice] != NULL && !my_strcmp(av[*indice], "-dump") &&
      option(av, indice, &param->dump))
    return (my_puterror
	    ("Corewar: Option -dump need a positif number after it.\n"));
  if (av[*indice] != NULL && !my_strcmp(av[*indice], "-rm"))
    {
      param->rand_mem = 1;
      *indice = *indice + 1;
    }
  if (av[*indice] != NULL && !my_strcmp(av[*indice], "-rr"))
    {
      param->rand_reg = 1;
      *indice = *indice + 1;
    }
  if (av[*indice] != NULL && !my_strcmp(av[*indice], "-ctmo") &&
      option(av, indice, &param->nbr_live))
    return (my_puterror
	    ("Corewar: Option -ctmo need a positif number after it.\n"));
  return (0);
}
