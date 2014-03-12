/*
** opt_o.c for opt_d in /home/platel_k/projet/my_printf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Nov 12 12:08:14 2011 kevin platel
** Last update Wed Nov 23 11:51:18 2011 kevin platel
*/

#include <stdarg.h>
#include "my.h"

#define ABS(x)		(x < 0)? x = (-x) : (x)

int	opt_o(va_list *ap, const char *format)
{
  unsigned int	j;
  int	i;
  unsigned int	k;

  if ((i = error(format)) < 0)
    return (-i);
  i = 0;
  k = va_arg(*ap, unsigned int);
  j = k;
  while ((j = j / 8) > 0)
    i++;
  i = opt_pres(format, i);
  j = 1;
  while (format[j] != '#' && find_intab(format[j]) == -1)
    j++;
  if (format[j] == '#')
    {
      my_putstr("0");
      i++;
    }
  my_putnbrul_base(k, "01234567");
  i = opt_less(format, (i + 1));
  return (i - 1);
}
