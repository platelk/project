/*
** data.c for data in /home/platel_k/projet/sys_unix/myselect/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 31 15:48:13 2012 kevin platel
** Last update Wed Feb 29 15:12:19 2012 kevin platel
*/

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"
#include "cmd.h"

char	treatment_of_data(void)
{
  char	buffer[5];

  buffer[0] = 0;
  buffer[1] = 0;
  buffer[2] = 0;
  if (read(0, buffer, 4) < 0)
    {
      write(2, "Can't read in stander input\n", 28);
      return (ERROR);
    }
  if (buffer[0] == QUIT)
    return (QUIT);
  else if (buffer[0] == ECHAP && buffer[1] == 0)
    return (ECHAP);
  else if (buffer[0] == SELECT)
    return (SELECT);
  else if (buffer[0] == DELETE)
    return (DELETE);
  else if (buffer[0] == 27)
    if (buffer[1] == 91)
      {
	if (buffer[2] == LEFT)
	  return (LEFT);
	else if (buffer[2] == RIGHT)
	  return (RIGHT);
      }
  return (buffer[0]);
}
