/*
** create_list_data_champ.c for Corewar in /home/guiho_r//tek1/corewar/source/VM/struct
**
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
**
** Started on  Fri Jan 27 14:56:03 2012 ronan guiho
** Last update Sun Mar 25 16:38:55 2012 alexandre deceneux
*/

#include <stdlib.h>

#include "corewar.h"
#include "data_champ.h"

int	create_list_data_champ(t_data_champ **list, char **av, int indice)
{
  t_data_champ	*ptr;
  t_data_champ	*tmp;
  static	int	id;
  static	int	addr;

  tmp = *list;
  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    return (-1);
  ptr->id = -1;
  ptr->addr = -1;
  indice = get_data_champ(ptr, av, indice);
  if (ptr->id == -1)
    ptr->id = --id;
  if (ptr->addr == -1)
    ptr->addr = --addr;
  ptr->next = NULL;
  if (*list != NULL)
    while (tmp && tmp->next)
      tmp = tmp->next;
  if (*list != NULL && tmp)
    tmp->next = ptr;
  if (*list == NULL)
    *list = ptr;
  return (indice);
}
