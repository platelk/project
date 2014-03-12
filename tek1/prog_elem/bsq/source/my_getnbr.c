/*
** my_getnbr.c for my_getnbr in /home/platel_k//lib
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 12:17:40 2011 kevin platel
** Last update Fri Dec  9 17:28:14 2011 kevin platel
*/

#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	nb;
  int	pow;
  int	signe;

  signe = 1;
  i = 0;
  while ((str[i] > '9' || str[i] < '0') && str[i] != '\0')
    i++;
  while (str[i] <= '9' && str[i] >= '0' && str[i] != '\0')
    i++;
  pow = 0;
  nb = 0;
  if (i != 0 && str[i - 1] == '-')
    signe = -1;
  if (i > 0)
    i--;
  while (str[i] != '\0' && str[i] <= '9' && str[i] >= '0')
    {
      nb = nb + ((str[i] - 48) * my_power_rec(10, pow));
      pow++;
      i--;
    }
  nb = nb * signe;
  return (nb);
}
