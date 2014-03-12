/*
** eval_expr.c for eval_expr.c in /home/przyby_m/projet/bistro
**
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
**
** Started on  Tue Nov  1 09:59:38 2011 matthieu przybylski
** Last update Fri Nov  2 10:21:31 2012 kevin platel
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

#define		OP_PRIO ((isop(temp->cha, op) % 7) == 0)

t_list		*calc(t_list *nb1, int isop, t_list *nb2, char *num, char *op)
{
  t_list	*result;
  int		bool_add;

  bool_add = 0;
  if (isop == 1)
    {
      result = add(nb1, nb2, num, op);
      if (nb1->cha == op[3] && result->cha != op[3])
	bool_add = 1;
    }
  else if (isop == 2)
    result = sub(nb1, nb2, num, op);
  else if (isop == 7)
    result = mult(nb1, nb2, num, op);
  else if (isop == 14)
    result = divi(nb1, nb2, num, op);
  else if (isop == 21)
    result = modu(nb1, nb2, num, op);
  while (result->befo != NULL)
    result = result->befo;
  if (bool_add == 1)
    add_before_list(&result, op[2]);
  return (result);
}

t_list		*analyse(char *expr, char *base, char *op)
{
  t_list	*list;

  if (no_double(base) != 0)
    return (NULL);
  if (no_double(op) != 0)
    return (NULL);
  if (is_empty(expr, base, op) != 0)
    return (NULL);
  if (val_cha(expr, base, op) != 0)
    return (NULL);
  tab_to_list(&list, expr, base, op);
  del_useless_par(&list, base, op);
  if (check_op(list, base, op) != 0)
    return (NULL);
  if (decrypt(&list, op, base) != 0)
    return (NULL);

  if (check_par(list, op) != 0)
    return (NULL);
  return (list);
}

char		*eval_expr(char *base, char *op, char *expr, unsigned int size)
{
  t_list	*temp;
  int		loop;

  if ((temp = analyse(expr, base, op)) == NULL)
    return (SYNTAXE_ERROR_MSG);
  loop = remaining_op(temp, op);
  while (loop == 1)
    {
      if (OP_PRIO && (isop((temp->next)->cha, op) != 4))
	{
	  get_prio_calc(&temp, base, op);
	  loop = remaining_op(temp, op);
	}
      else if (temp->next == NULL || isop(temp->cha, op) == 5)
	{
	  if (temp == NULL)
	    temp = temp->befo;
	  get_calc(&temp, base, op);
	  loop = remaining_op(temp, op);
	}
      else
	temp = temp->next;
    }
  return (list_to_tab(temp));
}
