/*
** check_base.c for check_base in /home/leprov_a//bdd/source/ps
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Jan 16 12:43:47 2012 alexis leprovost
** Last update Tue Apr 17 12:36:51 2012 alexis leprovost
*/

#include	"my.h"

int	check_base(char c, char *base)
{
  int i;

  i = -1;
  if (!base)
    return (0);
  while (base[++i])
    if (base[i] == c)
      return (1);
  return (0);
}
