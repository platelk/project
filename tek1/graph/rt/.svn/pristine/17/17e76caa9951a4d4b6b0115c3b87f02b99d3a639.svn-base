/*
** my_free_tab.c for my in /home/leprov_a//bdd/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 30 16:19:46 2012 alexis leprovost
** Last update Sat Jun  2 15:12:26 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

void	my_free_tab(char **tab)
{
  int i;

  i = -1;
  if (tab)
    {
      while (tab[++i])
	free(tab[i]);
      free(tab);
    }
}
