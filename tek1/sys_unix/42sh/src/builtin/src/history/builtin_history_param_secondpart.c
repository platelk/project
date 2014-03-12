/*
** builtin_history_param.c for 42sh in /home/phalip_z//exos/projets/42sh/42sh_builtin_history
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue May  1 11:38:31 2012 zoe phalippou
** Last update Sat May 12 19:09:38 2012 zoe phalippou
*/

#include	<string.h>
#include	<stdlib.h>
#include	<stdio.h>

#include	"history_showlist.h"

int	args_t(char **cmd, t_history **history)
{
  t_history *list;
  int	i;

  i = -1;
  list = advance_history(*history, cmd[1]);
  if (!cmd[1])
    while (list != NULL)
      {
	show_param_history(list);
	list = list->next;
      }
  else
    {
      if (put_error(cmd[1], 1))
	return (EXIT_FAILURE);
      while (list &&  ++i < atoi(cmd[1]))
	{
	  show_param_history(list);
	  list = list->next;
	}
    }
  return (EXIT_SUCCESS);
}
