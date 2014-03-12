/*
** my_getnbr.c for getnbr in /home/vink/projet/colle
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 19 14:17:44 2012 kevin platel
** Last update Thu Apr 19 14:57:18 2012 kevin platel
*/

#include	<stdlib.h>

int	my_power_rec(int nb, int pow)
{
  int	nbr;

  if (pow == 0)
    return (1);
  nbr = nb * my_power_rec(nb, pow - 1);
  return (nbr);
}

int	my_get_nbr(char *str)
{
  int	i;
  int	nb;
  int	pow;

  i = 0;
  nb = 0;
  if (str != NULL)
    {
      while ((str[i] > '9' || str[i] < '0') && str[i] != '\0')
	i = i + 1;
      while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
	i = i + 1;
      pow = 0;
      i--;
      while (i >= 0 && str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
	{
	  nb = nb + ((str[i] - 48) * my_power_rec(10, pow));
	  pow++;
	  i--;
	}
      if (i >= 0 && str[i] == '-')
	nb = nb * (-1);
    }
  return (nb);
}
