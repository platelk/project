/*
** malloc_tabint.c for libmy in /home/guiho_r/tek1/42sh/src/stack_exec/src/pipe
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Apr 15 17:53:07 2012 ronan guiho
** Last update Sat May 19 13:52:10 2012 alexis leprovost
*/

#include <stdlib.h>

int	**malloc_int_tab(int nb_col, int nb_ligne)
{
  int	i;
  int	**tab;

  i = 0;
  if ((tab = malloc(sizeof(int *) * (nb_col + 1))) == NULL)
    return (NULL);
  while (i < nb_col)
    {
      if ((tab[i] = malloc(sizeof(int) * nb_ligne)) == NULL)
	return (NULL);
      i++;
    }
  return (tab);
}
