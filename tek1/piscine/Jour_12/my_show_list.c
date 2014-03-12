/*
** my_show_list.c for my_show_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 10:59:27 2011 kevin platel
** Last update Tue Oct 25 20:01:57 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "stru.h"

void	my_show_list(t_list *list)
{
  t_list *temp;

  temp = list;
  while (temp != NULL)
    {
      my_putstr(temp->data);
      my_putchar('\n');
      temp = temp->next;
    }
}
