/*
** my_free_tab.c for colle in /home/vink/projet/colle/rendu/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Apr 27 00:05:37 2012 kevin platel
** Last update Fri Apr 27 00:09:38 2012 kevin platel
*/

#include	<stdlib.h>

void	my_free_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab && tab[i])
    {
      free(tab[i]);
      i++;
    }
  if (tab)
    free(tab);
}
