/*
** get_cmd.c for get_cmd in /home/platel_k/projet/sys_unix/minishell2/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 31 13:17:25 2012 kevin platel
** Last update Wed Feb 29 15:31:10 2012 kevin platel
*/

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include "cmd.h"

char	*get_cmd(void)
{
  int	j;
  int	i;
  char	str[1024];
  char	c;

  i = 0;
  j = 0;
  c = 0;
  while (c != QUIT)
    {
      c = treatment_of_data();
      if (c == LEFT || c == RIGHT)
	mov_curs(c, i, &j);
      else if (c != QUIT && c != DELETE && c >= 32)
	{
	  if (write(0, &c, 1) == -1)
	    write(2, "Error\n", 8);
	  str[j++] = c;
	  while (j >= i)
	    str[++i] = 0;
	}
    }
  write(0, "\n", 1);
  return (my_strdup(str));
}
