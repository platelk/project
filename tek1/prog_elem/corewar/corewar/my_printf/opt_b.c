/*
** opt_b.c for opt_b in /home/platel_k/projet/my_printf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Nov 13 10:46:46 2011 kevin platel
** Last update Sat Jan 14 12:37:36 2012 kevin platel
*/

#include <stdarg.h>
#include "my.h"

#define ABS(x)		(x < 0)? x = (-x) : (x)

int	opt_b(va_list *ap, const char *format)
{
  int	x;
  int	j;
  int	i;
  int	k;

  i = 1;
  k = va_arg(*ap, unsigned int);
  x = my_getnbr((char *) &format[1]);
  j = k;
  while ((j = j / 2) > 0)
    i++;
  while (format[j] != '-' && find_intab(format[j]) == -1)
    j++;
  if (format[j] != '-')
    while ((ABS(x)) > i++)
      my_putchar(' ');
  my_putnbrul_base(k, "01");
  j = 0;
  while (format[j] != '-' && find_intab(format[j]) == -1)
    j++;
  if (format[j] == '-')
    while ((ABS(x)) > i++)
      my_putchar(' ');
  return (x + i);
}
