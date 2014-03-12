/*
** opt_s.c for opt_s in /home/platel_k/projet/my_printf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov 11 13:22:59 2011 kevin platel
** Last update Wed Nov 23 11:50:51 2011 kevin platel
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

int	opt_s(va_list *ap, const char *format)
{
  char	*x;
  int	i;
  int	j;
  int	c;

  if ((i = error(format)) < 0)
    return (-i);
  j = 1;
  x = va_arg(*ap, char *);
  if (x == NULL)
    my_putstr("(null)");
  if (x == NULL)
    return (6);
  i = my_strlen(x);
  while (format[j] != '\0' && format[j] != '.' && find_intab(format[j]) == -1)
    j++;
  c = 0;
  if (format[j] == '.')
    i = my_getnbr(&format[1]);
  else
    c = opt_pres(format, i);
  j = 0;
  while (i-- > 0 && x[j] != '\0')
      my_putchar(x[j++]);
  return ((c = opt_less(format, c) - 1));
}
