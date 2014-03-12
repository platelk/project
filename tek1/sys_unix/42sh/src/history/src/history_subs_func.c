/*
** subs_func_history.c for 42sh in /home/phalip_z//exos/projets/42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue Apr 10 15:36:44 2012 zoe phalippou
** Last update Sat May 19 16:31:31 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"my.h"
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
  while (list && list->next)
    list = list->next;
  n = -1;
  if (cmd == NULL || (cmd && cmd[0] == '\0'))
    return (NULL);
  while (cmd && cmd[++n]);
  if (n > 0 && cmd[n - 1] == '?')
    cmd[n - 1] = 0;
  while (list != NULL && list->command && strstr(list->command, cmd) == NULL)
    list = list->prev;
  if (list == NULL)
    return (NULL);
  if (list->command)
    cmd = list->command;
  list = tmp;
  return (cmd);
}

char	*subs_letter(char *cmd, t_history *list)
{
  t_history	*tmp;

  tmp = list;
  while (list && list->next)
    list = list->next;
  if (cmd == NULL || list->command == NULL)
    return (NULL);
  while (list != NULL
	 && my_strncmp(cmd, list->command, my_strlen(cmd + 1)) != 0)
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
  while (tmp && tmp->next)
    tmp = tmp->next;
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
  while (tmp && tmp->next)
    tmp = tmp->next;
  if (!cmd[1])
    {
      fprintf(stderr, "!: Command not found.\n");
      return (NULL);
    }
  ascend = atoi(&cmd[1]);
  while (tmp != NULL && --ascend)
    tmp = tmp->prev;
  if (tmp == NULL)
    {
      fprintf(stderr, "The previous event %s was not found.\n", &cmd[1]);
      return (NULL);
    }
  cmd = tmp->command;
  return (cmd);
}
