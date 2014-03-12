/*
** history_substitution.c for 42sh in /home/phalip_z//exos/projets/42sh/42sh_history
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Wed Apr 18 20:32:26 2012 zoe phalippou
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"t_history.h"
#include	"history_create_ptr_func.h"

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
  if (flag == 4)
    fprintf(stderr, "The previous event %s was not found.\n", &cmd[2]);
  return (NULL);
}

char	*history_substitution(char *cmd, t_history *list, char **type_str)
{
  int	i;
  ptr_f_history subs[5];
  char *save_cmd;

  save_cmd = strdup(cmd);
  create_ptr_func_history(subs);
  i = -1;
  if (cmd && cmd[0])
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
      if ((cmd = subs[i](&cmd[1], list)) == NULL)
	return (puterror(save_cmd, i));
      printf("%s\n", cmd);
      return (cmd);
    }
  return (NULL);
}
