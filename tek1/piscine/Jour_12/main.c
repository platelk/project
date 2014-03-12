/*
** main.c for main in /home/platel_k//projet/piscine/Jour_12
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 25 10:16:16 2011 kevin platel
** Last update Tue Oct 25 20:28:57 2011 kevin platel
*/

#include <stdlib.h>
#include "stru.h"
#include "my.h"

int	main(int argc, char **argv)
{
  t_list	*begin;

  begin = my_params_in_list(argc, argv);
  my_put_elem_in_sort_list(&begin, "{", &my_strcmp);
  my_show_list(begin);
  return (0);
}
