/*
** my_param_to_tab.c for my_param_to_tab in /home/platel_k//projet/piscine/Jour_09/ex_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct 13 11:14:10 2011 kevin platel
** Last update Fri Oct 14 18:49:50 2011 kevin platel
*/

#include <stdlib.h>
#include "stru.h"
#include "my.h"

t_stock_par	 newstruct(char *param)
{
  t_stock_par	inf_param;

  inf_param.size_param = my_strlen(param);
  inf_param.str = param;
  inf_param.copy = my_strdup(param);
  inf_param.tab = my_str_to_wordtab(param);

  return (inf_param);
}

struct s_stock_par *my_param_to_tab(int ac, char **av)
{
  int	i;
  struct s_stock_par *tab;

  i = 0;
  tab = malloc((ac + 1) * sizeof(t_stock_par));
  while (ac > i)
    {
      tab[i] = newstruct(av[i]);
      i = i + 1;
    }
  tab[i].str = 0;
  return (tab);
}
