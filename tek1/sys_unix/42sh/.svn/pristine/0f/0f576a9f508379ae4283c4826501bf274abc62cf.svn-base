/*
** exec_check_slash.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 12 17:12:31 2012 ronan guiho
** Last update Mon Apr 23 17:42:03 2012 harold ozouf
*/

#include <stdlib.h>
#include "token.h"

int	exec_check_slash(char *cmd)
{
  int	i;

  i = 0;
  while (cmd[i])
    {
      if (cmd[i] == '/' || cmd[i] == '.')
	return (TRUE);
      i++;
    }
  return (FALSE);
}
