/*
** my_apply_on_list.c for my_apply_on_list in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 14:35:36 2011 kevin platel
** Last update Tue Oct 25 15:02:16 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "stru.h"

int	my_apply_on_list(t_list *begin, int (*f)())
{
  while (begin != NULL)
    {
      (*f)(begin->data);
      begin = begin->next;
    }
}
