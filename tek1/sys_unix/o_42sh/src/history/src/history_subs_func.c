/*
** subs_func_history.c for 42sh in /home/phalip_z//exos/projets/42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue Apr 10 15:36:44 2012 zoe phalippou
** Last update Tue May  1 18:53:06 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"t_history.h"

char	*subs_exclamation_mark(char *cmd, t_history *list)
{
  if (list != NULL)
    cmd = list->command;
  else
    return (NULL);
  return (cmd);
}

char	*subs_interogation_mark(char *cmd, t_history *list)
{
  t_history	*tmp;
  int		n;

  tmp = list;
  n = -1;
  while (cmd && cmd[++n]);
  if (n > 0 && cmd[n - 1] == '?')
    cmd[n - 1] = 0;
  while (list != NULL && strstr(list->command, &cmd[1]) == NULL)
    list = list->prev;
  if (list == NULL)
    return (NULL);
  cmd = list->command;
  list = tmp;
  return (cmd);
}

char	*subs_letter(char *cmd, t_history *list)
{
  t_history	*tmp;

  tmp = list;
  while (list != NULL && strncmp(cmd, list->command, strlen(cmd)) != 0)
    list = list->prev;
  if (list == NULL)
    return (NULL);
  cmd = list->command;
  list = tmp;
  return (cmd);
}

char	*subs_nbr(char *cmd, t_history *list)
{
  t_history	*tmp;
  int		ascend;

  tmp = list;
  ascend = atoi(cmd);
  while (list != NULL && ascend != list->id_cmd)
    list = list->prev;
  if (list == NULL)
    return (NULL);
  cmd = list->command;
  list = tmp;
  return (cmd);
}

char	*subs_back_in_history(char *cmd, t_history *list)
{
  t_history	*tmp;
  int		ascend;

  tmp = list;
  ascend = atoi(&cmd[1]);
  while (list != NULL && --ascend)
    list = list->prev;
  if (list == NULL)
    return (NULL);
  cmd = list->command;
  list = tmp;
  return (cmd);
}
