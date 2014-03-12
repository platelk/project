/*
** take_nb.c for take_nb in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 13:53:59 2011 kevin platel
** Last update Fri Oct 28 15:50:36 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "function.h"

t_list		*take_nb(t_list **begin)
{
  t_list	*nb;
  t_list	*temp;

  temp = (*begin);
  nb = init_list(&nb);
  while(my_is_num(temp->cha))
    temp = temp->next;
  nb->cha = temp->cha;
  temp = temp->next;
  while (temp != NULL && (my_is_num(temp->cha) == 0))
    {
      nb = add_in_list(&nb, temp->cha);
      temp = temp->next;
    }
  return (nb);
}
