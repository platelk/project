/*
** go_to_end.c for Bistromathique in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Mon Nov  7 11:06:06 2011 matthieu przybylski
** Last update Mon Nov  7 11:06:25 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

void	go_to_end(t_list **list)
{
  while ((*list) != NULL && (*list)->next != NULL)
    (*list) = (*list)->next;
}
