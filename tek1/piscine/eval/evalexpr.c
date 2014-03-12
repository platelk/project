/*
** evalexpr.c for evalexpr in /home/platel_k//projet/piscine/eval
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 17:14:12 2011 kevin platel
** Last update Mon Oct 31 14:14:28 2011 kevin platel
*/

#include <stdlib.h>
#include "function.h"
#include "list.h"

int		main(int argc, char **argv)
{
  int		i;
  t_list	*begin;
  t_list	*temp;

  i = 0;
 
  if (argc == 1)
    return (0);
  begin = init_list(&begin);
  begin->cha = argv[1][i];
  temp = begin;

  i = i + 1;
  while (argv[1][i] != '\0')
    {
      begin = add_in_list(&begin, argv[1][i]);
      i = i + 1;
    }

  while (temp->cha != ')' && temp->next != NULL)
    temp = temp->next;
  while (temp->cha != '(' && temp->befo != NULL)
    temp = temp->befo;

  my_putchar('\n');
  my_show_list(begin);
  my_putchar('\n');
  my_show_list(temp);
  my_putchar('\n');

  return (0);
}
