/*
** init_list.c for init_list in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Oct 28 13:37:29 2011 kevin platel
** Last update Thu Nov  3 16:48:26 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"

t_list		*init_list(t_list **begin, char c)
{
  (*begin) = malloc(sizeof(*begin));
  if (begin == NULL)
    return (NULL);
  (*begin)->cha = c;
  (*begin)->next = NULL;
  (*begin)->befo = NULL;
  return ((*begin));
}
