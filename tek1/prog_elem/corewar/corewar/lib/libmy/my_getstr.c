/*
** point.c for point in /home/leprov_a//project/igraph/wolf3d/v_05/src/event
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Jan 12 15:31:48 2012 alexis leprovost
** Last update Wed Mar  7 12:14:04 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"rt.h"

char	*my_getstr(int nb)
{
  char *str;
  int len;
  int i;
  int k;

  i = 2;
  k = 0;
  len = nb;
  while ((len = len / 10))
    i++;
  if ((str = malloc(sizeof(*str) * i)) == NULL)
    return (NULL);
  while (--i)
    {
      len = (nb / my_power_rec(10, k)) % 10;
      str[i - 1] = (char)(len + 48);
      k++;
    }
   return (str);
}
