/*
** my_getnbr.c for my_getnbr in /home/platel_k//lib
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 12:17:40 2011 kevin platel
** Last update Thu Mar 22 13:20:05 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"

int	my_getnbr(char *str)
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
