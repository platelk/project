/*
** get_link.c for get_link in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Nov 21 21:27:01 2011 kevin platel
** Last update Tue Nov 22 21:16:11 2011 kevin platel
*/

#include <stdlib.h>

char	**get_link(int ac, char **av)
{
  int	i;
  int	j;
  char	**link;
  int	count;

  i = 0;
  count = 1;
  while (++i < ac)
    if ((av[i][0] == '-' && av[i][1] == '\0') || av[i][0] != '-')
      count++;
    else if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == '\0')
      count++;
  if ((link = malloc(count * sizeof(*link))) == NULL)
    exit(0);
  i = 0;
  j = 0;
  while (++i < ac)
    {
      if ((av[i][0] == '-' && av[i][1] == '\0') || av[i][0] != '-')
	link[j++] = av[i];
      else if (av[i][0] == '-' && av[i][1] == '-' && av[i][2] == '\0')
	link[j++] = av[i];
    }
  link[j] = NULL;
  return (link);
}
