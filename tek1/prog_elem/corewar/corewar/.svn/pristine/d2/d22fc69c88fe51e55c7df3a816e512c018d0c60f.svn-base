/*
** my_free_tab.c for my_free_tab in /home/leprov_a//bdd/source/ps
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Jan 16 13:43:58 2012 alexis leprovost
** Last update Mon Jan 16 13:45:57 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

void	my_free_tab(char **tab)
{
  int i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
