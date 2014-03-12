/*
** my_putfloat.c for float in /home/guiho_r/tek1/rt/lib
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jun  3 04:56:15 2012 ronan guiho
** Last update Sun Jun  3 09:00:03 2012 ronan guiho
*/

#include <stdlib.h>

#include "my.h"

char	*my_revstr1(char *str);
void	my_put_nbr_float(int nb, int point, char *base)
{
  int	i;
  char	*str;
  int	result;

  i = -1;
  str = malloc(10);
  if (nb == 0)
    my_putchar('0');
  else
    {
      while (nb != 0)
	{
	  if (i == point)
	    str[++i] = '.';
	  else
	    {
	      result = nb % my_strlen(base);
	      nb = nb / my_strlen(base);
	      str[++i] = base[result];
	    }
	}
    }
  my_putstr(my_revstr1(str));
  free(str);
}

int	my_put_nbr_base(long nb, char *base, int flag)
{
  long	i;
  char	*str;
  long	lenght;
  long	result;

  i = -1;
  str = malloc(20);
  lenght = my_strlen(base);
  if (nb == 0)
    my_putchar('0');
  else
    {
      while (nb != 0)
	{
	  result = nb % lenght;
	  nb = nb / lenght;
	  str[++i] = base[result];
	}
    }
  if (flag == 0)
    my_putstr(my_revstr1(str));
  else
    return (my_strlen(str));
  return (EXIT_SUCCESS);
}

int		my_putdouble(double val)
{
  int		i1;
  int		dec;
  int		val1;
  int		inter;

  dec = 1;
  i1 = -1;
  val1 = val;
  while (++i1 < my_put_nbr_base(val1, "0123456789", 1))
    dec = dec * 10;
  inter = val * dec;
  my_put_nbr_float(inter, my_put_nbr_base(val1, "0123456789", 1) - 1, \
		   "0123456789");
  return (EXIT_SUCCESS);
}
