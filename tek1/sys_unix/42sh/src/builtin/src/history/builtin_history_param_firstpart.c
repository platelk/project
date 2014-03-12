/*
** builtin_history_param.c for 42sh in /home/phalip_z//exos/projets/42sh/42sh_builtin_history
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue May  1 11:38:31 2012 zoe phalippou
** Last update Wed May  9 15:54:05 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	<string.h>
#include	<unistd.h>

#include	"history_showlist.h"
#include	"xsys.h"
#include	"my.h"

int	args_c(char **cmd, t_history **history)
{
  int	fd;

  if (cmd[1])
    if (put_error(cmd[1], 1))
      return (EXIT_FAILURE);
  if ((fd = open(".history", O_TRUNC, 0, NO)) == -1)
    return (EXIT_FAILURE);
  close(fd);
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
      if (put_error(cmd[1], 1))
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
  list = advance_history(*history, cmd[1]);
  if (!cmd[1])
    while (list != NULL)
      {
	printf("%s\n", list->command);
	list = list->next;
      }
  else
    {
      if (put_error(cmd[1], 1))
	return (EXIT_FAILURE);
      while (list &&  ++i < atoi(cmd[1]))
	{
	  printf("%s\n", list->command);
	  list = list->next;
	}
    }
  return (EXIT_SUCCESS);
}

int	args_s(char **cmd, t_history **history)
{
  int	fd;
  t_history *list;

  list = *history;
  if (!cmd[1])
    return (EXIT_FAILURE);
  if ((fd = xopen(cmd[1], O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR
		  | S_IWUSR | S_IRGRP | S_IROTH, NO)) == -1)
    return (EXIT_FAILURE);
  while (list && list->prev != NULL)
      list = list->prev;
  while (list != NULL)
    {
      write (fd, list->command, strlen(list->command));
      write (fd, "\n", strlen("\n"));
      list = list->next;
    }
  return (EXIT_SUCCESS);
}

int	args_l(char **cmd, t_history **history)
{
  cmd = cmd;
  *history = *history;
  return (EXIT_SUCCESS);
}
