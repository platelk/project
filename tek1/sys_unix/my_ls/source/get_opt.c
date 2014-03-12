/*
** get_opt.c for get_opt.c in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Nov 21 19:44:13 2011 kevin platel
** Last update Sun Dec  4 08:21:13 2011 kevin platel
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "my_ls.h"

int	get_opt(int ac, char **av)
{
  int	i;
  int	opt;
  int	j;

  i = 0;
  opt = 0;
  while (++i < ac)
    {
      j = 0;
      if ((av[i][0]) == '-')
	{
	  if (av[i][1] == '-')
	    find_in_list_str(av[i], &opt);
	  else
	    while (av[i][++j])
	      find_in_opt(av[i][j], &opt);
	}
    }
  return (opt);
}

void	find_in_opt(char c, int *opt)
{
  int	i;
  char	*list;

  i = -1;
  list = "lRrtdha";
  while (list[++i] && c != list[i]);
  if (list[i] == '\0')
    {
      my_printf("Enter a valid option\n");
      exit(1);
    }
  if (c == 'l' && ((*opt) & 1) != 1)
    *opt += 1;
  if (c == 'R' && ((*opt) & 2) != 2)
    *opt += 2;
  if (c == 'r' && ((*opt) & 4) != 4)
    *opt += 4;
  if (c == 't' && ((*opt) & 8) != 8)
	*opt += 8;
  if (c == 'd' && ((*opt) & 16) != 16)
    *opt += 16;
  if (c == 'h' && ((*opt) & 32) != 32)
    *opt += 32;
  if (c == 'a' && ((*opt) & 64) != 64)
    *opt += 64;
}

void	find_in_list_str(char *str, int *opt)
{
  if (str[2] != '\0')
    {
      if (my_strcmp(str, "--list") == 0 && ((*opt) & 1) != 1)
	*opt += 1;
      else if (my_strcmp(str, "--Recursive") == 0 && ((*opt) & 2) != 2)
	*opt += 2;
      else if (my_strcmp(str, "--reverse") == 0 && ((*opt) & 4) != 4)
	*opt += 4;
      else if (my_strcmp(str, "--time") == 0 && ((*opt) & 8) != 8)
	*opt += 8;
      else if (my_strcmp(str, "--directory") == 0 && ((*opt) & 16) != 16)
	*opt += 16;
      else if (my_strcmp(str, "--help") == 0 && ((*opt) & 32) != 32)
	*opt += 32;
      else if (my_strcmp(str, "--all") == 0 && ((*opt) & 64) != 64)
	*opt += 64;
      else if ((*opt) == 0)
	{
	  my_printf("Error, invalid option\n");
	  exit(1);
	}
    }
}
