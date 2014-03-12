/*
** init.c for init in /home/platel_k/projet/sys_unix/myselect/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Jan 12 10:45:32 2012 kevin platel
** Last update Wed Feb 29 15:59:07 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "minishell.h"

char	*get_term(char **envp)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (envp[i] != NULL && my_strstr(envp[i], "TERM") == NULL)
    i++;
  if (envp[i] == NULL)
    return (NULL);
  while (envp[i][j] != 0 && envp[i][j - 1] != '=')
    j++;
  if (envp[i][j] == 0)
    return (NULL);
  return (&envp[i][j]);
}

int	init(char **envp)
{
  tgetent(NULL, get_term(envp));
  if (raw_mode(SET) == ERROR)
    return (-1);
  if (echo_mode(UNSET) == ERROR)
    return (-1);
  stop_signal();
  return (0);
}
