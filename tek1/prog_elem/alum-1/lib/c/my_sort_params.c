/*
** my_sort_params.c for my_sort_params in /home/platel_k//projet/piscine/Jour_07/ex_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 11 14:32:40 2011 kevin platel
** Last update Wed Nov 23 11:09:02 2011 kevin platel
*/

#include "my.h"

int	my_sort_param(int argc, char **argv)
{
  int	i;
  char *p;

  i = 0;
  while (argc - 1 > i)
    {
      if (my_strcmp(argv[i], argv[i + 1]) > 0)
	{
	  p = argv[i];
	  argv[i] = argv[i + i];
	  argv[i + 1] = p;
	  my_putstr(argv[i]);
	}
      i = i + 1;
    }
  i = 0;
  while (argc > i)
    {
      my_putstr(argv[i]);
      my_putchar('\n');
      i = i + 1;
    }
  return (0);
}
