/*
** take_nb.c for take_nb in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 13:53:59 2011 kevin platel
** Last update Wed Nov  2 17:58:12 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

t_list		*take_nb(t_list *begin, char *ref_num)
{
  t_list	*nb;
  t_list	*temp;

  temp = begin;
  nb = NULL;
  nb = add_in_list(&nb, temp->cha);
  if (nb == NULL)
    return (0);
  temp = temp->next;
  if (temp != NULL && isnum(temp->cha, ref_num) == 1)
    {
      while (temp != NULL && isnum((temp)->cha, ref_num) == 1)
	{
	  nb = add_in_list(&nb, (temp->cha));
	  temp = temp->next;
	}
    }
  return (nb);
}
