/*
** opt_c.c for opt_c in /home/platel_k/projet/my_printf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov 11 14:30:58 2011 kevin platel
** Last update Sun Dec  4 08:15:44 2011 kevin platel
*/

#include <stdarg.h>
#include "my.h"

int	opt_c(va_list *ap, const char *format)
{
  int	x;
  int	c;

  c = 1;
  c = opt_pres(format, c);
  x = va_arg(*ap, int);
  my_putchar((char) x);
  c = opt_less(format, c);
  return (1);
}
