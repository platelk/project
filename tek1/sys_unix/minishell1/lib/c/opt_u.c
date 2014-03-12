/*
** opt_u.c for opt_u in /home/platel_k/projet/my_printf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Nov 13 10:43:59 2011 kevin platel
** Last update Wed Nov 23 11:58:33 2011 kevin platel
*/

#include <stdarg.h>
#include "my.h"

#define ABS(x)		(x < 0)? x = (-x) : (x)

int	opt_u(va_list *ap, const char *format)
{
  int	j;
  int	i;
  int	k;

  if ((i = error(format)) < 0)
    return (-i);
  i = 0;
  k = va_arg(*ap, unsigned int);
  j = k;
  while (j > 0)
    {
      j = j / 10;
      i++;
    }
  i = opt_pres(format, i);
  my_putnbrul_base(k, "0123456789");
  i = opt_less(format, i);
  return (i + 1);
}
