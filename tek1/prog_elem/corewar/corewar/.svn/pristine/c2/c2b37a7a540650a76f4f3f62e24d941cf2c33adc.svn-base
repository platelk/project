/*
** free_data_champ.c for corewar in /home/leprov_a//depot/corewar/source/VM/free
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Mar  7 11:44:39 2012 alexis leprovost
** Last update Wed Mar  7 11:45:58 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"corewar.h"

void	free_data_champ(t_data_champ *data)
{
  t_data_champ	*tmp;

  while (data != NULL)
    {
      tmp = data->next;
      free(data->name);
      free(data);
      data = tmp;
    }
}
