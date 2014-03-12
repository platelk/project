/*
** parser_free.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr  4 15:27:05 2012 ronan guiho
** Last update Thu Apr  5 14:35:39 2012 ronan guiho
*/

#include <stdlib.h>

#include "lemin.h"

void	parser_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}
