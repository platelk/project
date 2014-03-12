/*
** my_printf.c for my_printf in /home/platel_k/projet/my_printf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 10:17:01 2011 kevin platel
** Last update Sat Nov 19 18:32:11 2011 kevin platel
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"
#include "printf.h"

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;
  int		j;
  int		cont;

  i = -1;
  va_start(ap, format);
  cont = 0;
  while (format[++i])
    {
      if (format[i] != '%')
	my_putchar(format[i]);
      else
	opt(format, &i, &cont, &ap);
      cont++;
    }
  va_end(ap);
  return (cont);
}

int	opt(const char *format, int *i, int *cont, va_list *ap)
{
  int	(*(*tab))(va_list *, const char *);
  int	j;

  j = *i;
  tab = init_tab_func();
  if (format[*i + 1] == '%')
    {
      my_putchar('%');
      (*i)++;
      my_putchar(format[*i]);
      return (1);
    }
  while (format[*i + 1] != '\0' && find_intab(format[*i + 1]) == -1)
    (*i)++;
      if (format[(*i) + 1] == '\0')
	{
	  my_putchar('%');
	  (*i) = j;
	  return (-1);
	}
  (*cont) = tab[find_intab(format[++(*i)])](&(*ap), &format[j]) + ((*cont) - 1);
  return (0);
}
