/*
** calc_mult.c for Bistromathique in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Mon Nov  7 13:49:14 2011 matthieu przybylski
** Last update Mon Nov  7 17:20:02 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

#define		BASE_NB1	my_char_base(nb1, num)

t_list		*calc_mult(t_list *nb1, t_list *nb2, char *num, char *op)
{
  int		i;
  t_list	*content;

  i = 0;
  content = NULL;
  while (BASE_NB1 != i)
    {
      content = add(list_cpy(nb2), content, num, op);
      i = i + 1;
    }
  i = 1;
  while (my_list_size(nb1) != i)
    {
      content = add_in_list(&content, num[0]);
      i = i + 1;
    }
  return (content);
}
