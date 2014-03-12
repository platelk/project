/*
** exit.c for exit in /home/vink/projet/sys_unix/42sh
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 24 12:33:57 2012 kevin platel
** Last update Sat May 12 02:23:58 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>

#include	"my.h"
#include	"builtin.h"
#include	"global.h"

int	builtin_exit(t_global *g, char **cmd)
{
  int	len;

  len = my_tablen(cmd);
  if (len > 2 || (len == 2 && isanumber(cmd[1])))
    {
      fprintf(stderr, "exit: Expression Syntax\n");
      return (EXIT_FAILURE);
    }
  my_putstr("exit\n");
  g->status = !g->status;
  if (len == 2 && !isanumber(cmd[1]))
    {
      g->exit = my_getnbr(cmd[1]);
      return (my_getnbr(cmd[1]));
    }
  g->exit = EXIT_SUCCESS;
  return (EXIT_SUCCESS);
}
