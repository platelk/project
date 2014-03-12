/*
** my_find_str.c for my_find_str.c in /home/vink/projet/graph/rtv1/lib/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  8 11:13:30 2012 kevin platel
** Last update Wed Feb  8 11:23:16 2012 kevin platel
*/

#include <stdlib.h>

int	my_find_str(char *str, char *to_find)
{
  int	i;
  int	j;

  i = 0;
  if (str == NULL || to_find == NULL)
    return (0);
  while (str[i])
    {
      j = 0;
      while (str[i] && to_find[j] && str[i] == to_find[j])
	{
	  j++;
	  i++;
	}
      if (to_find[j] == 0)
	return (1);
      if (str[i] != 0)
	i++;
    }
  return (-1);
}
