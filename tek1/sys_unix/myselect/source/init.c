/*
** init.c for init in /home/platel_k/projet/sys_unix/myselect/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Jan 12 10:45:32 2012 kevin platel
** Last update Tue Feb 19 15:15:18 2013 vink
*/

#include <stdlib.h>
#include "my.h"
#include "myselect.h"

int	init_select(t_element **list, t_term **term, char **av, int ac)
{
  (*list) = creat_list(av, ac);
  (*term) = init_term_info();
  if ((*list) == NULL)
    {
      my_printf("List empty\n");
      return (ERROR);
    }
  raw_mode(SET);
  echo_mode(UNSET);
  visible_cursor(UNSET);
  return (0);
}

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
