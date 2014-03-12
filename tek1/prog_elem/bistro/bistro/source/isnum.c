/*
** isnum.c for Bistromathique in /home/przyby_m/projet/bistro
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Tue Nov  1 10:52:23 2011 matthieu przybylski
** Last update Fri Nov  4 09:26:57 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

/*
** RETURN VALUES :
** num = 1;
** other = 0;
*/
int	isnum(char c, char *ref)
{
  int	i;
  
  i = 0;
  while (ref[i] != '\0')
    {
      if (c == ref[i])
	return (1);
      i = i + 1;
    }
  return (0);
}
