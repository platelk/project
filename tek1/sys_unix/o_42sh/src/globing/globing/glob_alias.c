/*
** glob_alias.c for 42sh in /home/vink/projet/sys_unix/42sh/src/globing/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Apr 23 10:43:30 2012 kevin platel
** Last update Tue May  1 13:21:33 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"my.h"
#include	"alias.h"
#include	"utils.h"

void	res_alias(t_alias *alias)
{
  
  while (alias)
    {
      if (alias->flag <= 1)
	alias->flag = 0;
      alias = alias->next;
    }
}

char	*glob_alias(char *str, t_alias *alias, int *c)
{
  int	i;

  i = 0;
  while (alias)
    {
      if (my_strcmp(str, alias->initial) == 0 && alias->flag == 0)
	{
	  alias->flag = *c;
	  str = my_strdup(alias->alias);
	  i++;
	}
      alias = alias->next;
    }
  if (i == 0)
    *c = 0;
  return (str);
}
