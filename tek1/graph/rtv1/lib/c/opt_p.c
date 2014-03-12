/*
** opt_p.c for opt_p in /home/platel_k/projet/my_printf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Nov 15 14:38:22 2011 kevin platel
** Last update Wed Nov 23 11:51:02 2011 kevin platel
*/

#include <stdarg.h>
#include "my.h"

#define ABS(x)		(x < 0)? x = (-x) : (x)

int	opt_p(va_list *ap, const char *format)
{
  int	i;
  unsigned long int	k;
  unsigned long int	j;

  i = 0;
  k = va_arg(*ap, unsigned long long int);
  j = k;
  while (j > 0)
    {
      j = j / 16;
      i++;
    }
  i = opt_pres(format, i);
  my_putstr("0x");
  my_putnbrul_base(k, "0123456789abcdef");
  i = opt_less(format, i);
  return (i - 1);
}
