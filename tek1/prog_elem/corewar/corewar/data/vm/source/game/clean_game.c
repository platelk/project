/*
** clean_game.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/vm/source/game
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Sat Mar 24 18:19:21 2012 alexandre deceneux
** Last update Sun Mar 25 21:37:04 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"corewar.h"

int	counter_live(t_champ *champ, int id)
{
  t_champ	*tmp;
  int	nb_live;

  nb_live = 0;
  tmp = champ;
  while (tmp != NULL)
    {
      if (tmp->data[ID] == id)
	nb_live += tmp->data[LIVE];
      tmp = tmp->next;
    }
  return (nb_live);
}

int	clean_game(t_champ *champ)
{
  t_champ	*tmp;
  int	nb_champ_dead;
  int	nb_champ;

  nb_champ = 0;
  tmp = champ;
  nb_champ_dead = 0;
  while (tmp != NULL)
    {
      if (counter_live(champ, tmp->data[ID]) <= 0)
	{
	  tmp->data[LIVE] = -1;
	  ++nb_champ_dead;
	}
      else
	tmp->data[LIVE] = 0;
      nb_champ++;
      tmp = tmp->next;
    }
  return (nb_champ_dead);
}
