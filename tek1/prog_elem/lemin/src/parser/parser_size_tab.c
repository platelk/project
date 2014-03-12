/*
** parser_size_tab.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr  4 15:30:11 2012 ronan guiho
** Last update Thu Apr  5 12:05:43 2012 ronan guiho
*/

#include <stdlib.h>

#include "lemin.h"

int	parser_size_tab(char **tab)
{
  int	 i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}
