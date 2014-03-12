/*
** is.c for Bistromathique in /home/przyby_m/projet/bistro
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Tue Nov  1 10:52:23 2011 matthieu przybylski
** Last update Fri Nov  4 13:41:53 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

/*
** RETURN VALUES :
** add = 1 ; sub = 2
** mult = 7 ; div = 14 ; mod = 21
** par_open = 4 ; par_close = 5
** other = -1
*/
int	isop(char c, char *ref)
{
  if (c == ref[2])
    return (1);
  if (c == ref[3])
    return (2);
  else if (c == ref[4])
    return (7);
  else if (c == ref[5])
    return (14);
  else if (c == ref[6])
    return (21);
  else if (c == ref[0])
    return (4);
  else if (c == ref[1])
    return (5);
  else
    return (-1);
}
