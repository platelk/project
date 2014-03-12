/*
** opt_d.c for opt_d in /home/platel_k/projet/my_printf
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Fri Nov 11 12:50:22 2011 kevin platel
** Last update Thu Apr  5 11:08:52 2012 ronan guiho
*/

#include <stdarg.h>
#include "my.h"

#define ABS(x)		(x < 0)? x = (-x) : (x)

int	opt_d(va_list *ap, const char *format)
{
  int	j;
  int	i;
  int	k;

  if ((i = error(format)) < 0)
    return (-i);
  i = 0;
  k = va_arg(*ap, int);
  j = k;
  while ((ABS(j)) > 0)
    {
      j = j / 10;
      i++;
    }
  j = 1;
  i = opt_pres(format, i);
  while (format[j] != '+' && find_intab(format[j]) == -1)
    j++;
  if ((format[j] == '+' && k > 0) || (k < 0))
    i++;
  if (format[j] == '+' && k > 0)
    my_putchar('+');
  my_putnbr_base(k, "0123456789");
  i = opt_less(format, i);
  return (i - 1);
}
