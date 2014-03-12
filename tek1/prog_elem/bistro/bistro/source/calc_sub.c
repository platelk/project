/*
** calc_sub.c for calc_sub in /home/platel_k/projet/bistro/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov  3 16:04:56 2011 kevin platel
** Last update Mon Nov  7 11:10:19 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

t_list	*calc_sub(t_list *nb1, t_list *nb2, char *ref_num)
{
  int		int_nb1;
  int		int_nb2;
  int		ret;
  t_list	*result;

  ret = 0;
  result = NULL;
  while (nb1 != NULL || nb2 != NULL)
    {
      int_nb1 = my_char_base(nb1, ref_num);
      int_nb2 = my_char_base(nb2, ref_num);
      if (int_nb1 < (int_nb2 + ret))
	int_nb1 = int_nb1 + my_strlen(ref_num);
      int_nb2 = (int_nb1) - (int_nb2 + ret);
      ret = 0;
      if (int_nb1 >= my_strlen(ref_num))
	ret = 1;
      if (int_nb2 < 0)
	int_nb1 = int_nb1*(-1);
      result = add_before_list(&result, ref_num[int_nb2]);
      nb1 = del_one_in_list(&nb1);
      nb2 = del_one_in_list(&nb2);
   }
  return (result);
}
