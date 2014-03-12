/*
** glob_select_flag.c for glob in /home/vink/projet/sys_unix/42sh/src/globing/globing
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Thu May 10 11:06:14 2012 kevin platel
** Last update Fri May 11 20:03:13 2012 kevin platel
*/

#include	"globing.h"

int	my_is_in_str(char c, char *str)
{
  while (str && *str)
    {
      if (c == *str)
	return (0);
      str++;
    }
  return (1);
}

int	glob_select_flag(char *str, int pos)
{
  int	flag;

  flag = 0;
  if (pos == 0)
    flag |= GLOB_CMD | GLOB_ALIAS;
  if (str && str[0] == '$' && !my_is_in_str('*', str))
    flag |= GLOB_ENV;
  else
    flag |= GLOB_DIR;
  return (flag);
}
