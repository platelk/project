/*
** opt_mod.c for opt_mod in /home/platel_k/projet/my_printf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Nov 15 11:16:58 2011 kevin platel
** Last update Sat Jan 14 12:38:23 2012 kevin platel
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

int	opt_mod(va_list *ap, const char *format)
{
  int	i;

  ap = ap;
  if ((i = error(format)) < 0)
    return (-i);
  i = 1;
  my_putchar('%');
  return (i);
}
