/*
** add_char_to_begin.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/lib/libmy
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Tue Jan 31 10:23:04 2012 alexandre deceneux
** Last update Tue Jan 31 10:34:06 2012 alexandre deceneux
*/

#include <stdlib.h>
#include "my.h"

char	*add_char_to_begin(char *str, char c)
{
  char	*ret;
  int	i;

  i = 0;
  ret = malloc(sizeof(*ret) * (my_strlen(str) + 2));
  if (!ret)
    return (NULL);
  while (str[i++])
    ret[i] = str[i - 1];
  ret[0] = c;
  ret[i] = 0;
  if (str)
    free(str);
  return (ret);
}
