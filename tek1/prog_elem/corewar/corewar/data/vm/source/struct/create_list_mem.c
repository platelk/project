/*
** create_list_mem.c for create_list_mem in /home/leprov_a//depot/corewar/source/VM/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Feb  9 14:45:10 2012 alexis leprovost
** Last update Tue Mar 20 17:58:59 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"

int	create_list_mem(t_mem **begin, int flag, int indice)
{
  t_mem	*new_element;
  t_mem	*tmp;

  tmp = *begin;
  if ((new_element = malloc(sizeof(*new_element))) == NULL)
    return (-1);
  new_element->indice = indice;
  new_element->value = flag ? (unsigned char)get_rand_number(MAX) : 0;
  new_element->id = -1;
  new_element->state = NONE;
  new_element->color = get_color(0xffffff);
  new_element->next = NULL;
  if (*begin == NULL)
    {
      new_element->before = NULL;
      *begin = new_element;
    }
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      new_element->before = tmp;
      tmp->next = new_element;
    }
  return (0);
}
