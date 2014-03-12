/*
** opt_less.c for opt_less in /home/platel_k/projet/my_printf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Nov 15 08:51:21 2011 kevin platel
** Last update Fri Mar 23 14:46:46 2012 kevin platel
*/

#include <stdarg.h>
#include "my.h"

#define ABS(x)		(x < 0) ? (x = (-x)) : (x)

int	opt_less(const char *format, int i)
{
  int	x;
  int	j;

  x = my_getnbr((char *) &format[1]);
  j = 1;
  while (format[j] != '-' && find_intab(format[j]) == -1)
    j++;
  if (format[j] == '-')
    {
      j = 1;
      while (format[j] != '.' && find_intab(format[j]) == -1)
	j++;
      if (format[j] != '.' && i < ABS(x))
	while (i++ < -x)
	  my_putchar(' ');
      if (format[j] == '.')
	return (-1);
    }
  return (i);
}

int	opt_pres(const char *format, int i)
{
  int	x;
  int	j;

  x = my_getnbr((char *)format);
  j = 1;
  while (format[j] != '-' && find_intab(format[j]) == -1)
    j++;
  if (format[j] != '-')
    {
      j = 1;
      while (format[j] != '.' && find_intab(format[j]) == -1)
	j++;
      if (format[j] != '.')
	while (x > i++)
	  my_putchar(' ');
      if (format[j] == '.')
	while (x > i++)
	  my_putchar('0');
    }
  return (i);
}

int	error(const char *format)
{
  int	j;

  j = 1;
  while (format[j] != '-' && find_intab(format[j]) == -1)
    j++;
  if (format[j] == '-')
    {
      j = 1;
      while (format[j] != '.' && find_intab(format[j]) == -1)
	j++;
      if (format[j] == '.')
	{
	  j = 0;
	  my_putchar('%');
	  while (format[j++] != '\0' && find_intab(format[j]) == -1)
	    {
	      my_putchar(format[j]);
	      if (format[j] == '.')
		my_putchar('0');
	    }
	  my_putchar(format[j]);
	  return (-(j + 2));
	}
    }
  return (0);
}
