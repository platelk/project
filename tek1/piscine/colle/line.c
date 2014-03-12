/*
** line.c for line in /home/platel_k//projet/piscine/colle
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Oct  8 14:22:29 2011 kevin platel
** Last update Sun Oct 30 01:04:08 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "header.h"

/*
**This function diplays the others lines
*/
void	line(char tab, char *f_l_c, char c, char *str)
{
  int	i;

  i = 1;
  while (i <= tab)
    {
      if (i == 1)
	{
	  add_in_tab(str, f_l_c[0]);
	}
      else if (i == tab)
	{
	  add_in_tab(str, f_l_c[1]);
	}
      else
	{
	  add_in_tab(str, c);
	}
      i = i + 1;
    }
}
