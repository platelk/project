/*
** main.c for colle in /home/fontai_t/colle2
** 
** Made by thomas fontaine
** Login   <fontai_t@epitech.net>
** 
** Started on  Thu Apr 26 21:18:10 2012 thomas fontaine
** Last update Fri Apr 27 15:59:40 2012 kevin platel
*/

#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#include "sand_pile.h"
#include "check.h"
#include "alloc.h"
#include "put.h"
#include "get.h"
#include "count.h"
#include "free.h"

int	check_pos_nb(int nb, int nb1)
{
  if (nb <= 0)
    {
      my_puterr("Error in length (negative or null)\n");
      return (1);
    }
  if (nb1 <= 0)
    {
      my_puterr("Error in weight (negative or null)\n");
      return (1);
    }
  return (0);
}

char	**gen_map(int l, int h, char *sig)
{
  time_t ran1;
  char	**_tab;
  int	i;

  time(&ran1);
  srand(ran1);
  if (check_pos_nb(l, h) == 1)
    return (NULL);
  alloc_tab(&_tab, l + 1);
  _tab[l--] = NULL;
  while (l >= 0)
    {
      alloc_str(&_tab[l], h + 1);
      i = 0;
      while (i < h)
	{
	  _tab[l][i] = sig[rand() % 4];
	  i++;
	}
      _tab[l][i] = 0;
      l--;
    }
  return (_tab);
}

int	main(int ac, char **av)
{
  char	**map;

  if (check_user(ac, av) == 1)
    return (1);
  map = gen_map(getnbr(av[1]), getnbr(av[2]), av[3]);
  if (map == NULL)
    {
      my_puterr("Map failed\n");
      return (1);
    }
  run_simulation(map, av[3]);
  my_free_tab(map);
  my_putstr("quit\n");
  return (0);
}
