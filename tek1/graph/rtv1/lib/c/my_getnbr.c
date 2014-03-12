/*
** my_getnbr.c for my_getnbr in /home/platel_k//lib
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 12:17:40 2011 kevin platel
** Last update Thu Feb  9 15:49:43 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	pow;

  i = 0;
  if (str == NULL)
    return (0);
  while ((str[i] > '9' || str[i] < '0') && str[i] != '\0')
    i = i + 1;
  while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
    i = i + 1;
  pow = 0;
  nb = 0;
  if (i > 0)
    i--;
  while (i >= 0 && str && str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
    {
      nb = nb + ((str[i] - 48) * my_power_rec(10, pow));
      pow++;
      i--;
    }
  i = -1;
  while (str[++i] && str[i] != '-');
  str[i] == '-' ? (nb = nb * -1) : (nb = nb);
  return (nb);
}
