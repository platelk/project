/*
** main.c for main_my_ls in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Nov 21 17:32:52 2011 kevin platel
** Last update Sun Dec  4 14:09:19 2011 kevin platel
*/

#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "my_ls.h"

int	main(int ac, char **av)
{
  int	i;
  int	opt;
  char	**link;

  i = -1;
  opt = get_opt(ac, av);
  link = get_link(ac, av);
  if (link[0] == NULL)
    show_dir(".", opt);
  else
    while (link[++i] != NULL)
      {
	if (ac > 2 && (opt & 16) != 16)
	  my_printf("%s:\n", link[i]);
	show_dir(link[i], opt);
	if (ac > 2 && link[i + 1] != NULL)
	  my_printf("\n");
      }
  return (0);
}
