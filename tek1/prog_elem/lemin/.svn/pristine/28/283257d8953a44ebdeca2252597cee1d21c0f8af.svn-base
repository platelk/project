/*
** parser_free.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr  4 15:27:05 2012 ronan guiho
** Last update Fri Apr  6 17:13:34 2012 alexis leprovost
*/

#include <stdlib.h>

#include "hex.h"

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
