/*
** dump_mem.c for dump_mem in /home/leprov_a//depot/corewar/source/VM/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Feb  9 14:13:52 2012 alexis leprovost
** Last update Thu Mar 15 09:30:30 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"

t_mem	*dump_mem(t_param *param)
{
  t_mem	*mem;
  t_mem *tmp;
  int	i;

  i = -1;
  mem = NULL;
  while (++i <= MEM_SIZE)
    if (create_list_mem(&mem, param->rand_mem, i) == -1)
      return (NULL);
  tmp = mem;
  while (tmp->next != NULL)
    tmp = tmp->next;
  mem->before = tmp;
  tmp->next = mem;
  return (mem);
}
