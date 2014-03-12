/*
** init_tab_fun.c for init_tab_func in /home/platel_k/projet/my_printf/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sat Nov 12 08:46:56 2011 kevin platel
** Last update Fri Oct 26 15:50:03 2012 kevin platel
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"

void		*init_tab_func()
{
  int		(*(*tab))(va_list *, const char *);

  tab = malloc(11 * sizeof(*tab));
  tab[0] = &opt_d;
  tab[1] = &opt_S;
  tab[2] = &opt_c;
  tab[3] = &opt_x;
  tab[4] = &opt_x;
  tab[5] = &opt_o;
  tab[6] = &opt_u;
  tab[7] = &opt_b;
  tab[8] = &opt_S;
  tab[9] = &opt_p;
  tab[10] = &opt_mod;

  return (tab);
}
