/*
** get_extend.c for get_extend in /home/leprov_a//depot/corewar/source/ASM/data
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Jan 24 14:08:38 2012 alexis leprovost
** Last update Thu Mar 22 15:33:06 2012 alexis leprovost
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "corewar.h"
#include "get_next_line.h"

int	get_extend(int *flag, int fd, int *l)
{
  char	**tab;
  char	*tmp;
  char	*bdd;
  int	len;

  if ((tmp = jump_comment(fd, l)) == NULL)
      return (EXIT_FAILURE);
  bdd = my_strdup(".extend");
  tab = my_str_to_tab(tmp, bdd);
  len = EXIT_SUCCESS;
  if (my_tablen(tab) > 0 && !my_strcmp(tab[0], bdd))
    *flag = 1;
  else
    {
      *l = *l - 1;
      len = (my_strlen(tmp) + 1) * (-1);
      if (lseek(fd, len, SEEK_CUR) == -1)
	len = EXIT_FAILURE;
    }
  my_free_tab(tab);
  free(bdd);
  free(tmp);
  return (len);
}
