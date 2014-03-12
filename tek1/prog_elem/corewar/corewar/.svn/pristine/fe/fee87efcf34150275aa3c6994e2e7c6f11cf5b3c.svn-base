/*
** check_game.c for check_game in /home/leprov_a//depot/corewar/source/VM/game
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar  7 11:20:08 2012 alexis leprovost
** Last update Tue Mar 20 10:07:07 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"corewar.h"

int	check_game(t_champ *champ, int *nb_champ)
{
  int	i;
  int	nb_dead;

  nb_dead = 0;
  i = -1;
  while (++i < *nb_champ)
    {
      if (champ != NULL && champ->data[LIVE] < NBR_LIVE)
	{
	  *nb_champ = *nb_champ - 1;
	  nb_dead++;
	}
      else
	{
	  champ->data[LIVE] = 0;
	  champ = champ->next;
	}
    }
  if (nb_dead >= (*nb_champ - 1))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
