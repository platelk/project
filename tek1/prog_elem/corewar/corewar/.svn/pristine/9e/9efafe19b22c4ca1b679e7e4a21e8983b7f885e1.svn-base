/*
** create_list_champ.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Jan 29 14:38:12 2012 ronan guiho
** Last update Tue Mar 20 15:29:49 2012 alexis leprovost
*/

#include <stdlib.h>

#include "param.h"
#include "champ.h"
#include "corewar.h"
#include "data_champ.h"
#include "vm.h"

int		create_list_champ(t_champ **champ, t_data_champ *data)
{
  t_champ	*ptr;
  t_champ	*tmp;

  tmp = *champ;
  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    return (-1);
  if ((fill_struct_champ(ptr, data)) == 1)
    return (-1);
  ptr->next = NULL;
  if (*champ == NULL)
    {
      ptr->before = NULL;
      *champ = ptr;
    }
  else
    {
      while (tmp->next)
	tmp = tmp->next;
      ptr->before = tmp;
      tmp->next = ptr;
    }
  return (0);
}
