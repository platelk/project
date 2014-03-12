/*
** is_number.c<2> for is_number in /home/guiho_r/tmp
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May  6 17:02:36 2012 ronan guiho
** Last update Wed May 23 16:00:55 2012 ronan guiho
*/

#include "my.h"

int	is_number(char *str)
{
  int	i;

  i = 0;
  while (str[i] >= '0' && str[i] <= '9')
    i++;
  if (i == my_strlen(str))
    return (1);
  return (0);
}
