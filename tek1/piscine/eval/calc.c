/*
** calc.c for calc in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 15:38:11 2011 kevin platel
** Last update Fri Oct 28 15:55:11 2011 kevin platel
*/

#include "function.h"
#include "list.h"

int		calc(t_list **begin)
{
  t_list	*nb1;
  t_list	*nb2;
  t_list	*temp;

  temp = (*begin);
  nb1 = take_nb(begin);
  while (my_is_num(temp->cha))
    temp = temp->next;
  while (!my_is_num(temp->cha))
    temp = temp->next;
  nb2 = take_nb(&temp);
  my_show_list(nb1);
  my_show_list(nb2);
  return (0);
}
