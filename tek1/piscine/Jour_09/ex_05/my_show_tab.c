/*
** my_show_tab.c for my_show_tab in /home/platel_k//projet/piscine/Jour_09/ex_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct 13 14:05:26 2011 kevin platel
** Last update Fri Oct 14 22:35:50 2011 kevin platel
*/

#include <stdlib.h>
#include "stru.h"
#include "my.h"

int	my_show_tab(struct s_stock_par *par)
{
  int   i;

  i = 0;
  while (par[i].str != 0)
    {
      my_putstr(par[i].str);
      my_putchar('\n');
      my_put_nbr(par[i].size_param);
      my_putstr("\n");
      my_show_wordtab(par[i].tab);
      i = i + 1;
    }
}
