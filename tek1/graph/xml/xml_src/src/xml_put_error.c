/*
** xml_put_error.c for xml in /home/vink/projet/graph/xml/xml_src/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Sat May  5 14:06:28 2012 kevin platel
** Last update Sun May  6 09:33:37 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"my.h"

void	my_put_err_char(char c)
{
  write(2, &c, 1);
}

void	xml_error_putnbr(int nb)
{
  int	pow;

  pow = 1;
  if (nb < 0)
    {
      write(2, "-", 1);
      nb *= (-1);
    }
  while ((nb / pow) > 9)
    pow *= 10;
  while (pow > 0)
    {
      my_put_err_char((nb / pow) % 10 + 48);
      pow /= 10;
    }
}

int	xml_put_error(char *err, int l, char *err1, char *err2)
{
  write(2, "XML Error : line ", 12);
  xml_error_putnbr(l);
  write(2, " : ", 3);
  write(2, err, my_strlen(err));
  write(2, err1, my_strlen(err1));
  write(2, err2, my_strlen(err2));
  write(2, "\n", 1);
  return (EXIT_FAILURE);
}

int	xml_put_synt_error(int c, char *s, char *err, int l)
{
  int	i;

  write(2, "XML Error : line ", 17);
  xml_error_putnbr(l);
  write(2, " :\n\n=>'", 7);
  write(2, s, my_strlen(s));
  i = -1;
  write(2, "'\n   ", 4);
  while (++i < c)
    write(2, " ", 1);
  write(2, "/\\ ", 3);
  i = -1;
  write(2, "\n___", 3);
  while (++i < c)
    write(2, "_", 1);
  write(2, "/\n\n", 3);
  write(2, err, my_strlen(err));
  return (EXIT_FAILURE);
}
