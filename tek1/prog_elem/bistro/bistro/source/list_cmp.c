/*
** list_cmp.c for list_cmp in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov  3 11:26:10 2011 kevin platel
** Last update Tue Nov  8 14:41:45 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

#define BASE_NB(x)	my_char_base(x, ref_num)

/*
** RETURN VALUES :
** If list1 is longer than list2, this function returns 0
** If list1 is shorter than list2, this function returns 1
** If list1 is as long as list2, this function returns 3
*/

int	int_list(t_list *list1, t_list *list2, char *ref_num)
{
  if (my_list_size(list1) < my_list_size(list2))
    return (1);
  if ((my_list_size(list1)) > (my_list_size(list2)))
    return (0);
  while (list1 != NULL && list2 != NULL)
    {
      if ((BASE_NB(list1) - BASE_NB(list2)) < 0)
	{
	  return (1);
	}
      if ((BASE_NB(list1) - BASE_NB(list2)) > 0)
	{
	  return (0);
	}
      list1 = list1->next;
      list2 = list2->next;
    }
  return (3);
}
