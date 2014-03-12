/*
** treatement_champ.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jan 29 14:29:49 2012 ronan guiho
** Last update Tue Mar 20 15:31:23 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"
#include "vm.h"
#include "param.h"
#include "champ.h"
#include "data_champ.h"

t_champ		*treatment_champ(t_data_champ *data)
{
  t_champ	*champ;

  champ = NULL;
  while (data)
    {
      if (create_list_champ(&champ, data) == -1)
	return (NULL);
      data = data->next;
    }
  return (champ);
}
