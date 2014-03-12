/*
** my_power_rec.c for my in /home/leprov_a//bdd/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 30 16:23:56 2012 alexis leprovost
** Last update Mon Apr 30 16:27:11 2012 alexis leprovost
*/

#include	"my.h"

int	my_power_rec(int nb, int pow)
{
  if (nb == 1 || pow == 0)
    return (1);
  else if (nb == 0)
    return (0);
  else
    {
      if (pow == 1)
	return (nb);
      return (nb * my_power_rec(nb, pow - 1));
    }
}
