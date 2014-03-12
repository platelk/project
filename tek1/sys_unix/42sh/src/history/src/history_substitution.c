/*
** history_substitution.c for history in /home/vink/projet/sys_unix/42sh/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May  8 22:55:44 2012 kevin platel
** Last update Fri May 18 19:14:49 2012 zoe phalippou
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"t_history.h"
#include	"history_create_ptr_func.h"
#include	"my.h"

static char	*puterror(char *cmd, int flag)
{
  if (flag == 0)
    fprintf(stderr, "The previous event was not found.\n");
  if (flag == 1)
    fprintf(stderr, "%s: Event not found.\n", &cmd[2]);
  if (flag == 2)
    fprintf(stderr, "%s: Event not found.\n", &cmd[1]);
  if (flag == 3)
    fprintf(stderr, "The event %s was not found.\n", &cmd[1]);
  return (NULL);
}

char	*history_substitution(char *cmd, t_history *list, char **type_str)
{
  int	i;
  ptr_f_history subs[7];
  char *save_cmd;

  save_cmd = my_strdup(cmd);
  create_ptr_func_history(subs);
  i = -1;
  if (cmd && cmd[0] && cmd[1])
    while (subs[++i] && strchr(type_str[i], cmd[1]) == NULL);
  else
    return (NULL);
  if (subs[i] == NULL)
    {
      fprintf(stderr, "%s : Event not found.\n", cmd);
      return (NULL);
    }
  if (cmd && cmd[0] && cmd[1])
    {
      if (i == 1 && ((cmd = subs[i](&cmd[2], list)) == NULL))
	return (puterror(save_cmd, i));
      if ((cmd = subs[i](&cmd[1], list)) == NULL)
	return (puterror(save_cmd, i));
      return (cmd);
    }
  return (NULL);
}
