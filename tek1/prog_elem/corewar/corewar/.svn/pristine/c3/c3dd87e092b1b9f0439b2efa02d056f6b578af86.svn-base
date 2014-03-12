/*
** jump_comment.c for jump_comment in /home/leprov_a//depot/corewar/source/ASM/data
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Feb  7 17:30:25 2012 alexis leprovost
** Last update Tue Mar 13 11:23:05 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"
#include "get_next_line.h"
#include "op.h"

char	*jump_comment(int fd, int *l)
{
  char	**tab;
  char	*tok;
  char	*tmp;
  int	flag;

  flag = 0;
  tok = my_strdup("\t\n ");
  while (!flag && (tmp = get_next_line(fd, l)))
    {
      tab = my_strtok(tmp, tok);
      if (tab != NULL && my_tablen(tab) >= 1)
	{
	  if (tab[0][0] != COMMENT_CHAR)
	    flag++;
	}
      else
	free(tmp);
      my_free_tab(tab);
    }
  free(tok);
  return (tmp);
}
