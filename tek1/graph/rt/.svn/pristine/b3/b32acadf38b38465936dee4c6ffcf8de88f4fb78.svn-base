/*
** my_getdouble.c for my_getdouble in /home/leprov_a//project/igraph/rt/v_1/src/tool
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Feb  2 21:46:50 2012 alexis leprovost
** Last update Wed May  9 11:38:22 2012 alexis leprovost
*/

#include	"my_strtok.h"
#include	"my.h"

double	my_getdouble(char *str)
{
  double	nb;
  char	**tab;
  int	pow;
  int	i;

  i = 0;
  pow = 0;
  if ((tab = my_strtok(str, DELIM_NUMBER, TOK_DELIM)) == NULL)
    return (0.000);
  nb = (double)(my_getnbr(tab[i]));
  while (tab[++i])
    {
      nb += (double)(my_getnbr(tab[i])) /
	(double)my_power_rec(10, my_strlen(tab[i]) - pow);
      pow--;
    }
  my_free_tab(tab);
  return (nb);
}
