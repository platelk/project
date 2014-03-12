/*
** action_in_cmd.c for action_in_cmd in /home/platel_k/projet/sys_unix/myselect/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 31 15:59:40 2012 kevin platel
** Last update Wed Apr 25 09:44:28 2012 kevin platel
*/

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include "cmd.h"

int   mov_curs(int c, int i, int *j)
{
  if (c == LEFT && (*j - 1) >= 0)
    {
      use_termcap("le");
      (*j)--;
    }
  else if (c == RIGHT && ((*j + 1) <= (i)))
    {
      use_termcap("nd");
      (*j)++;
    }
  return (0);
}

int	put_rv(char c)
{
  if (use_termcap("mr") == ERROR)
    return (ERROR);
  write(0, &c, 1);
  if (use_termcap("me") == ERROR)
    return (ERROR);
  return (0);
}
