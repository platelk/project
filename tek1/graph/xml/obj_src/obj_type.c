/*
** obj_type.c for obj in /home/vink/projet/graph/xml/obj_src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May  8 12:33:56 2012 kevin platel
** Last update Tue May  8 12:37:38 2012 kevin platel
*/

#include	<stdlib.h>

#include	"object.h"
#include	"my.h"

int	obj_get_type(char *name)
{
  char	*tab[NB_TYPE + 1];
  int	i;

  tab[0] = STRING_SPH;
  tab[1] = STRING_PLA;
  tab[2] = STRING_CYL;
  tab[NB_TYPE] = NULL;
  i = 0;
  while (tab[i])
    {
      if (my_strcmp(tab[i], name) == 0)
	return (i);
      i++;
    }
  return (-1);
}
