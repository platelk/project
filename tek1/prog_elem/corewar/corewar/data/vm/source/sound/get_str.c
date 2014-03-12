/*
** get_str.c for corewar in /home/guiho_r/tek1/corewar/source/VM/sound
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar  7 13:28:54 2012 ronan guiho
** Last update Wed Mar  7 14:58:34 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

char	*my_getstr(int nb, char *base)
{
  int	i;
  char	*str;
  int	lenght;
  int	result;

  i = -1;
  if ((str = malloc(sizeof(char) * (20 + 1))) == NULL)
    return (NULL);
  lenght = my_strlen(base);
  if (nb == 0)
    {
      str[0] = '0';
      str[1] = '\0';
    }
  else
    {
      while (nb != 0)
	{
	  result = nb % lenght;
	  nb = nb / lenght;
	  str[++i] = base[result];
	}
      str[++i] = '\0';
    }
  return (my_revstr(str));
}
