/*
** my_putnbr.c for putnbr in /home/vink/projet/colle/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 19 14:27:01 2012 kevin platel
** Last update Thu Apr 19 16:01:46 2012 kevin platel
*/

#include	<stdio.h>
#include	"master.h"

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_putnbr_rec(int nb)
{
  char	c;

  if (nb == 0)
    return (0);
  my_putnbr_rec(nb / 10);
  c = (nb % 10) + 48;
  write(1, &c, 1);
}

int	my_putnbr(int nb)
{
  if (nb == 0)
    my_putchar('0');
  else
    my_putnbr_rec(nb);
}

int	put_error_pion(char c)
{
  write(1, "-> ", 3);
  write(1, &c, 1);
  my_putstr(" n'est pas un pion valide\n");
  return (-1);
}
