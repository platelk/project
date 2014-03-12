/*
** my_getnbr_base.c for my in /home/vink/projet/graph/rt
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Wed May  9 04:10:47 2012 kevin platel
*/

#include	"my.h"

int	join(char value, char *base)
{
  int i;

  i = 0;
  while (base[i])
    {
      if (base[i] == value)
	return (i);
      i++;
    }
  return (-1);
}

int	my_getnbr_base(char *str, char *base)
{
  int nb;
  int i;
  int value;
  int power;

  if (!str || !base)
    return (0);
  power = 0;
  i = my_strlen(str) - 1;
  nb = 0;
  value = 0;
  while (i >= 0 && check_base(str[i], base) &&
	 (value = join(str[i], base)) >= 0)
    {
      nb = (value * my_power_rec(my_strlen(base), power)) + nb;
      power++;
      i--;
    }
  if (i >= 0 && str[i] == '-')
    nb = nb * (-1);
  return (nb);
}
