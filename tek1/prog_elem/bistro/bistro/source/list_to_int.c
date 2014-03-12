/*
** list_to_int.c for list_to_int in /home/przyby_m/projet/bistro
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Tue Nov  1 09:40:15 2011 matthieu przybylski
** Last update Wed Nov  2 17:19:04 2011 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

int		val(char *ref_num, char c)
{
  int	i;

  i = 0;
  while (c != ref_num[i])
    i = i + 1;
  return (i);
}

int		list_to_int(t_list *begin, char *ref_num, char *ref_op, int size)
{
  t_list	*temp;
  int		nb;
  int		i;

  i = 0;
  nb = 0;
  temp = begin;
  if (begin != NULL)
    {
      while (temp->next != NULL)
	temp = temp->next;
      while (temp != NULL && i < size && isnum(temp->cha, ref_num) == 1)
	{
	  nb = nb + (val(ref_num, temp->cha) * my_power_rec(my_strlen(ref_num), i));
	  i = i + 1;
	  temp = temp->befo;
	}
    }
  if (temp != NULL && isop(temp->cha, ref_op) == 2)
    nb = nb * -1;
  return (nb);
}
