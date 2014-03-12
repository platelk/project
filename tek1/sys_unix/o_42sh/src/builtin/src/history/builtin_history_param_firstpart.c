/*
** builtin_history_param.c for 42sh in /home/phalip_z//exos/projets/42sh/42sh_builtin_history
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue May  1 11:38:31 2012 zoe phalippou
** Last update Tue May  1 17:52:00 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"history_showlist.h"

int	args_c(char **cmd, t_history **history)
{
  if (cmd[1])
    if (put_error(cmd[1]))
      return (EXIT_FAILURE);
  *history = NULL;
  return (EXIT_SUCCESS);
}

int	args_r(char **cmd, t_history **history)
{
  t_history *list;
  int	i;

  i = -1;
  list = *history;
  if (!cmd[1])
    while (list != NULL)
      {
	show_param_history(list);
	list = list->prev;
      }
  else
    {
      if (put_error(cmd[1]))
	return (EXIT_FAILURE);
      while (list &&  ++i < atoi(cmd[1]))
	{
	  show_param_history(list);
	  list = list->prev;
	}
    }
  return (EXIT_SUCCESS);
}

int	args_h(char **cmd, t_history **history)
{
  t_history *list;
  int	i;

  i = -1;
  list = *history;
  if (!cmd[1])
    while (list != NULL)
      {
	printf("%s\n", list->command);
	list = list->prev;
      }
  else
    {
      if (put_error(cmd[1]))
	return (EXIT_FAILURE);
      while (list &&  ++i < atoi(cmd[1]))
	{
	  printf("%s\n", list->command);
	  list = list->prev;
	}
    }
  return (EXIT_SUCCESS);
}

int	args_s(char **cmd, t_history **history)
{
  cmd = cmd;
  *history = *history;
  return (EXIT_SUCCESS);
}

int	args_l(char **cmd, t_history **history)
{
  cmd = cmd;
  *history = *history;
  return (EXIT_SUCCESS);
}
