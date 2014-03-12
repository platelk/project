/*
** pop_champ.c for vm in /home/leprov_a//project/corewar/data/VM/source/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Mar 15 09:31:30 2012 alexis leprovost
** Last update Sat Mar 24 16:54:02 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"corewar.h"

int	write_champ_in_mem(t_champ *champ, t_mem *mem)
{
  t_mem	*tmp;
  int	i;

  tmp = mem;
  i = -1;
  while (tmp->indice != champ->data[ADDR])
    tmp = tmp->next;
  while (++i < champ->prog_size)
    {
      tmp->value = (int)champ->bin[i];
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

int	pop_champ(t_champ *champ, t_mem *mem)
{
  t_champ	*tmp;

  tmp = champ;
  while (tmp != NULL)
    {
      if (write_champ_in_mem(tmp, mem) == EXIT_FAILURE)
	return (EXIT_FAILURE);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
