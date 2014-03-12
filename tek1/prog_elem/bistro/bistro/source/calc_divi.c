/*
** calc_divi.c for Bistromathique in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Tue Nov  8 13:46:37 2011 matthieu przybylski
** Last update Thu Nov 10 09:20:20 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

#define ADD(x, y)	add(list_cpy(x), list_cpy(y), num_op[1], num_op[2])

int	divide_spe(t_list *nb1, t_list *nb2, char *num)
{
  if (my_list_size(nb2) == 1 && nb2->cha == num[0])
    return (-1);
  if (int_list(nb1, nb2, num) == 1)
    return (0);
  if (my_list_size(nb1) == 1 && nb2->cha == num[0])
    return (0);
  return (42);
}

int	calc_div(t_list **test,t_list *nb_cpy, char **num_op, t_list *nb2)
{
  int	i;

  i = 0;
  (*test) = NULL;
  while (int_list((*test), nb_cpy, num_op[1]) == 1)
    {
      i = i + 1;
      (*test) = ADD((*test), nb2);
    }
  return (i);
}

char	**concat_char(char *num, char *op)
{
  char **concat;
  int	i;

  i = 0;
  concat = malloc(2 * sizeof(*concat));
  concat[1] = malloc((my_strlen(num) + 1) * sizeof(**concat));
  concat[2] = malloc((my_strlen(op) + 1) * sizeof(**concat));
  while (num[i])
    {
      concat[1][i] = num[i];
      i = i + 1;
    }
  concat[1][i] = '\0';
  i = 0;
  while (op[i])
    {
      concat[2][i] = op[i];
      i = i + 1;
    }
  concat[2][i] = '\0';
  return (concat);
}

void	init_nb_cpy(t_list **nb_cpy, t_list *r, t_list *nb1, char *ref_num)
{
  (*nb_cpy) = list_ncpy(nb1, 1);
  concat(nb_cpy, &r);
  (*nb_cpy) = del_us_zero(nb_cpy, ref_num);
}

void	init_div(t_list **result, t_list **r, t_list **nb2, char *ref_num)
{
  (*result) = NULL;
  (*r) = NULL;
  (*nb2) = del_us_zero(nb2, ref_num);
}
