/*
** history_subs_func_dollar.c for 42sh in /home/phalip_z//42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Sat May 12 10:36:33 2012 zoe phalippou
** Last update Fri May 18 13:52:48 2012 ronan guiho
*/

#include	<stdlib.h>

#include	"t_history.h"

static char    *trunc_str(char *str)
{
  int   i;

  i = -1;
  while (str[++i]);
  while ((str[i] != ' ' && str[i] != '\t') && --i != 0);
  if (i == 0)
    str = &str[i];
  else
    str = &str[i + 1];
  return (str);
}

char	*subs_dollar(char *cmd, t_history *list)
{
  if (list)
    cmd = trunc_str(list->command);
  else
    return (NULL);
  return (cmd);
}
