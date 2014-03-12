/*
** my_getnbr2.c for my_getnbr.c in /u/all/guiho_r/rendu/lib/my
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon Oct 24 13:24:32 2011 ronan guiho
** Last update Mon Jan 30 09:11:38 2012 ronan guiho
*/
#include "my.h"

int	my_getnbr(char *str)
{
  int	i;
  int	i1;
  int	result;

  i = 0;
  i1 = 1;
  result = 0;
  while (str[i] == 45 || str[i] == 43)
    {
      if (str[i] == 45)
	i1 = i1 * (-1);
      i = i + 1;
    }
  while (str[i] < 58 && str[i] > 47)
    result = (result + (str[i++]) - (48)) * 10;
  result = result / 10;
  if (i1 == -1)
    result = result * i1;
  return (result);
}
