/*
** colle.c for colle in /home/platel_k//projet/piscine/colle
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Oct  8 16:47:56 2011 kevin platel
** Last update Sun Oct 30 01:23:09 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "header.h"

void	colle(char *test)
{
  int	i;
  char	tab[8];
  int	x;
  int	y;
  char	*str;

  x = 5;
  y = 5;
  i = 1;

  str = malloc((x * ( y + 1)) * sizeof(char));

  tab[0] = '/';
  tab[1] = '\\';
  tab[2] = '\\';
  tab[3] = '/';
  tab[4] = '*';
  tab[5] = '*';
  tab[6] = '*';
  tab[7] = x;
  tab[8] = y;


  select_line(&tab[0], str);
  my_putstr(str);
}
