/*
** my_printf.c for my_printf in /home/platel_k/projet/my_printf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 10:17:01 2011 kevin platel
** Last update Sun Jun  3 08:20:49 2012 ronan guiho
*/

#include <stdarg.h>
#include <stdlib.h>
#include "my.h"

#define IS_NOT_OPT  (find_intab(format[*i + 1]) == -1)

int		my_printf(const char *format, ...)
{
  va_list	ap;
  int		i;
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
  while (format[(*i) + 1] != '\0' && IS_NOT_OPT && is_alpha(format[*i]) == 1)
    (*i)++;
  if (format[(*i) + 1] == '\0' || IS_NOT_OPT)
    {
      my_putchar('%');
      (*i) = j;
      free(tab);
      return (-1);
    }
  (*cont) = (tab[(int)find_intab(format[++*i])](&(*ap),
						&format[j])) + ((*cont) - 1);
  free(tab);
  return (0);
}
