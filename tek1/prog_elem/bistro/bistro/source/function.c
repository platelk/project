/*
** do-op.c for do_op in /home/platel_k//projet/piscine/Jour_11/do-op
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 10:52:25 2011 kevin platel
** Last update Thu Nov 10 09:33:30 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

#define R_EQ_NB2        (int_list(r, nb2, ref_num) == 3)
#define R_EQ_0          (my_list_size(r) == 1 && r->cha == ref_num[0])
#define R_EQ_CPY        (result == NULL && int_list(r, nb_cpy, ref_num) == 1)
#define SIZE_NB1        (result == NULL && my_list_size(nb1) == 1 && R_MOD_NB2 == 0)
#define R_MOD_NB2       (my_char_base(r, ref_num) % my_char_base(nb2, ref_num))

#define MULT(x, y)	mult(list_cpy(x), list_cpy(y), ref_num, ref_op)
#define SUB(x, y)	sub(list_cpy(x), list_cpy(y), ref_num, ref_op)
#define ADD(x, y)	add(list_cpy(x), list_cpy(y), ref_num, ref_op)
#define	EQ_ZERO(x)	(my_list_size(x) == 1 && (x)->cha == ref_num[0])

t_list		*add(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op)
{
  int		int_nb1;
  int		int_nb2;
  int		ret;
  t_list	*result;

  ret = 0;
  result = NULL;
  if (nb1 != NULL && isop(nb1->cha, ref_op) == 2)
    {
      result = (sub(del_one_in_list(&nb1), nb2, ref_num, ref_op));
      return (add_before_list(&result, ref_op[3])); 
    }
  go_to_end(&nb1);
  go_to_end(&nb2);
  while (nb1 != NULL || nb2 != NULL || ret != 0)
    {
      int_nb1 = my_char_base(nb1, ref_num) + my_char_base(nb2, ref_num);
      int_nb2 = (int_nb1 + ret) % my_strlen(ref_num);
      ret = (int_nb1 + ret) / my_strlen(ref_num);
      result = add_before_list(&result, (ref_num[int_nb2]));
      nb1 = del_one_in_list(&nb1);
      nb2 = del_one_in_list(&nb2);
    }
  return (del_us_zero(&result, ref_num));
}

t_list		*sub(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op)
{
  t_list	*result;
  int		signe;

  signe = 0;
  if (nb1 != NULL && isop(nb1->cha, ref_op) == 2)
    {
      result = add(del_one_in_list(&nb1), nb2, ref_num, ref_op);
      return (add_before_list(&result, ref_op[3]));
    }
  if (int_list(nb1, nb2, ref_num) == 1)
    {
      result = nb2;
      nb2 = nb1;
      nb1 = result;
      signe = 1;
    }
  result = NULL;
  go_to_end(&nb1);
  go_to_end(&nb2);
  result = calc_sub(nb1, nb2, ref_num);
  result = del_us_zero(&result, ref_num);
  if (signe == 1)
    add_before_list(&result, ref_op[3]);
  return (result);
}

t_list		*mult(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op)
{
  t_list	*result;
  int		signe;
  t_list	*content;

  result = NULL;
  signe = signe_mult(&nb1, &nb2, ref_op);
  if (EQ_ZERO(nb1) || EQ_ZERO(nb2))
  {
    init_list(&result, ref_num[0]);
    return (result);
  }
  while (nb1 != NULL)
    {
      content = calc_mult(nb1, nb2, ref_num, ref_op);
      result = add(list_cpy(result), content, ref_num, ref_op);
      del_one_in_list(&nb1);
    }
  if ((signe % 2) == 1)
    result = add_before_list(&result, ref_op[3]);
  return (del_us_zero(&result, ref_num));
}

t_list          *divi(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op)
{
  t_list        *nb_cpy;
  t_list        *result;
  t_list        *test;
  t_list        *r;
  int           i;

  init_div(&result, &r, &nb2, ref_num);
  signe_divi(&nb1, &nb2, &result, ref_op);
  if (divide_spe(nb1, nb2, ref_num) == 0)
    return (add_in_list(&result, ref_num[0]));
  else if (divide_spe(nb1, nb2, ref_num) == -1)
    return (NULL);
  while (nb1 != NULL)
    {
      init_nb_cpy(&nb_cpy, r, nb1, ref_num);
      i = calc_div(&test, nb_cpy, concat_char(ref_num, ref_op), nb2);
      r = define_r(result, SUB(nb_cpy, SUB(test, nb2)), nb_cpy, ref_op);
      if (my_list_size(nb_cpy) == 1 && nb_cpy->cha == ref_num[0])
        add_in_list(&result, ref_num[0]);
      else if (R_EQ_NB2 || R_EQ_0 || SIZE_NB1 || R_EQ_CPY)
        add_in_list(&result, ref_num[i % my_strlen(ref_num)]);
      else
        add_in_list(&result, ref_num[(i - 1) % my_strlen(ref_num)]);
      nb1 = del_one_in_list(&nb1);
    }
  return (del_us_zero(&(result), ref_num));
}

t_list          *modu(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op)
{
  t_list        *nb_cpy;
  t_list        *result;
  t_list        *test;
  t_list        *r;
  int           i;

  init_div(&result, &r, &nb2, ref_num);
  signe_divi(&nb1, &nb2, &result, ref_op);
  result = nb2;
  if (divide_spe(nb1, nb2, ref_num) == 0)
    return (add_in_list(&result, ref_num[0]));
  else if (divide_spe(nb1, nb2, ref_num) == -1)
    return (NULL);
  while (nb1 != NULL)
    {
      init_nb_cpy(&nb_cpy, r, nb1, ref_num);
      i = calc_div(&test, nb_cpy, concat_char(ref_num, ref_op), nb2);
      r = define_r(result, SUB(nb_cpy, SUB(test, nb2)), nb_cpy, ref_op);
      nb1 = del_one_in_list(&nb1);
      if (int_list(r, result, ref_num) == 3)
	{
	  free(r);
	  r = init_list(&r, ref_num[0]);
	}
    }
  return (del_us_zero(&(r), ref_num));
}
