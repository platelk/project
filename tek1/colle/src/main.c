/*
** main.c for main in /home/vink/projet/colle/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 26 21:15:08 2012 kevin platel
** Last update Thu Apr 26 22:58:42 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>

int	main(int ac, char **av)
{
  char	**tab;

  tab = malloc(5 * sizeof(*tab));
  tab[0] = strdup("   32");
  tab[1] = strdup("3 3 2");
  tab[2] = strdup("1 321");
  tab[3] = strdup("1 33 ");
  tab[4] = NULL;
  sand_pile(tab, " 123", 3);
  return (0);
}
