/*
** str_concat.c for corewar in /home/guiho_r/tek1/corewar/source/VM/sound
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar  7 12:50:17 2012 ronan guiho
** Last update Wed Mar  7 15:03:14 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

char	*my_str_concat(char *dest, char *str)
{
  char	*rtrn;

  if ((rtrn = malloc(sizeof(char) * (my_strlen(str) + \
				     my_strlen(dest) + 1))) == NULL)
    return (NULL);
  my_strcpy(rtrn, dest);
  return (my_strcat(rtrn, str));
}
