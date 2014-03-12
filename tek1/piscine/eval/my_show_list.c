/*
** my_show_list.c for my_show_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 10:59:27 2011 kevin platel
** Last update Fri Oct 28 11:29:45 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include <unistd.h>
#include "function.h"

void	my_putchar(char a)
{
write(1, &a,1);
}

void	my_show_list(t_list *list)
{
  t_list *temp;

  temp = list;
  while (temp != NULL && temp->cha != '\0')
    {
      my_putchar(temp->cha);
      temp = temp->next;
    }
}
