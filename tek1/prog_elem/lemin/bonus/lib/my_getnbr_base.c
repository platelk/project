/*
** my_getnbr_base.c for my_getnbr_base in /home/leprov_a//bdd/source/others/test
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Nov 28 11:26:19 2011 alexis leprovost
** Last update Mon Apr  2 09:29:29 2012 alexis leprovost
*/

#include	"my.h"

int	join(char value, char *base)
{
  int i;

  i = 0;
  while (base[i] != value)
    i++;
  return (i);
}

int	my_getnbr_base(char *str, char *base)
{
  int nb;
  int i;
  int value;
  int power;

  power = 0;
  i = my_strlen(str) - 1;
  nb = 0;
  while (i >= 0 && check_base(str[i], base))
    {
      value = join(str[i], base);
      nb = (value * my_power_rec(my_strlen(base), power)) + nb;
      power++;
      i--;
    }
  if (str[i] == '-')
    nb = nb * (-1);
  return (nb);
}
