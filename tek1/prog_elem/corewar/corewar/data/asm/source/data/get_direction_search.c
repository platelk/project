/*
** get_direction_search.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/source/ASM/data
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Wed Jan 25 14:24:26 2012 alexandre deceneux
** Last update Thu Feb 16 14:47:34 2012 kevin platel
*/

#include <stdlib.h>
#include "corewar.h"

int	get_direction_search(char *label, t_instruction *instruct)
{
  int	i;
  t_label	*search;

  search = instruct->label;
  while (search != NULL)
    {
      i = -1;
      while (search->name[++i] != NULL)
	if (my_strcmp(label, search->name[i]) == 0)
	  return (-1);
      search = search->prev;
    }
  search = instruct->label;
  while (search != NULL)
    {
      i = -1;
      while (search->name[++i] != NULL)
	if (my_strcmp(label, search->name[i]) == 0)
	  return (1);
      search = search->next;
    }
  return (0);
}
