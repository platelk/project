/*
** my_add_list_to_list.c for my_add_list_to_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 16:31:56 2011 kevin platel
** Last update Tue Oct 25 16:51:39 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "stru.h"

int	my_add_list_to_list(t_list **begin1, t_list *begin2)
{
  t_list *temp;

  temp = (*begin1);
  while (((*begin1)->next) != NULL)
    (*begin1) = (*begin1)->next;
  (*begin1)->next = begin2;
  (*begin1) = temp;
}
