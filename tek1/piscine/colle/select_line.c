/*
** f_l_line.c for f_l_line in /home/manour_m//test_c/colle01
** 
** Made by manuel manoury
** Login   <manour_m@epitech.net>
** 
** Started on  Sat Oct  8 14:29:50 2011 manuel manoury
** Last update Sun Oct 30 01:10:30 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "header.h"

/*
** This function add in string line
*/

void	select_line(char *tab, char *str)
{
  int	i;

  i = 0;
  while (i < tab[8])
    {
      i = i + 1;
      if (i == 1)
	{
	  line(tab[7], &tab[0], tab[4], str);
	}
      else if (i == tab[8])
	{
	  line(tab[7], &tab[2], tab[4], str);
	}
      else
	{
	  line(tab[7], &tab[5], ' ', str);
	}
      add_in_tab(str, '\n');
    }
}
