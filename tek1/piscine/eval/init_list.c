/*
** init_list.c for init_list in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 13:37:29 2011 kevin platel
** Last update Fri Oct 28 13:52:35 2011 kevin platel
*/

#include "list.h"
#include <stdlib.h>

t_list		*init_list(t_list **begin)
{

  (*begin) = malloc(sizeof(*begin));
  if (begin == NULL)
    return (0);
  (*begin)->cha = 0;
  (*begin)->next = NULL;
  (*begin)->befo = NULL;

  return ((*begin));
}
