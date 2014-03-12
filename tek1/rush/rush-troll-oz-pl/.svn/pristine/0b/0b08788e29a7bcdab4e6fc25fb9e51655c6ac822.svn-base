/*
** opt_S.c for opt_S in /home/platel_k/projet/my_printf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Nov 13 10:49:38 2011 kevin platel
** Last update Tue Dec 20 19:52:54 2011 kevin platel
*/

#include <stdarg.h>
#include "my.h"

int	put_oct(char c)
{
  char	i;
  char	c_cpy;

  i = 3;
  c_cpy = c;
  while (c_cpy > 0)
    {
      c_cpy = c_cpy / 8;
      i--;
    }
  my_putchar('\\');
  while (i-- > 0)
    my_putchar('0');
  my_putnbr_base(c, "01234567");
  return (3);
}

int	opt_S(va_list *ap, const char *format)
{
  char	*x;
  int	i;
  int	j;
  int	c;

  if ((i = error(format)) < 0)
    return (-i);
  j = 1;
  x = va_arg(*ap, char *);
  i = my_strlen(x);
  while (format[j] != '\0' && format[j] != '.' && find_intab(format[j]) == -1)
    j++;
  if (format[j] == '.')
    i = my_getnbr((char *) &format[1]);
  j = -1;
  c = 0;
  while (i-- > 0 && x[++j] != '\0')
    {
      if (x[j] < 32 || x[j] >= 127)
	c = put_oct(x[j]) + c;
      else
	my_putchar(x[j]);
      c++;
    }
  return (c);
}
