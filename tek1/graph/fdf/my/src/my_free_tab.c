/*
** my_free_tab.c for my_free_tab in /home/leprov_a//bdd/source/ps
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Jan 16 13:43:58 2012 alexis leprovost
** Last update Sat Apr 28 16:22:29 2012 ronan guiho
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
