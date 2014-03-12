/*
** get.c for colle in /home/fontai_t/colle2
** 
** Made by thomas fontaine
** Login   <fontai_t@epitech.net>
** 
** Started on  Thu Apr 26 21:18:31 2012 thomas fontaine
** Last update Thu Apr 26 21:19:16 2012 thomas fontaine
*/

#include	<stdlib.h>

int	pwer(int nb, int pow)
{
  int	nbr;

  if (pow == 0)
    return (1);
  nbr = nb * pwer(nb, pow - 1);
  return (nbr);
}

int	getnbr(char *str)
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
	  nb = nb + ((str[i] - 48) * pwer(10, pow));
	  pow++;
	  i--;
	}
      if (i >= 0 && str[i] == '-')
	nb = nb * (-1);
    }
  return (nb);
}
