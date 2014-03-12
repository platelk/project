/*
** builtin_ptr_func.c for builtin in /home/vink/projet/sys_unix/42sh/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May  8 22:56:43 2012 kevin platel
** Last update Sat May 19 14:09:11 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>

#include "t_history.h"
#include "builtin.h"
#include "global.h"

builtin_ptr_f	*builtin_create_ptr_func(builtin_ptr_f *p)
{
  p[0] = &cd;
  p[1] = &check_setenv;
  p[2] = &check_unsetenv;
  p[3] = &check_history;
  p[4] = &echo;
  p[5] = &builtin_exit;
  p[6] = &builtin_alias;
  p[7] = &builtin_unalias;
  p[8] = &cd;
  p[9] = NULL;
  return (p);
}

int	builtin_ptr_func(char **cmd, t_global *global)
{
  int	i;
  builtin_ptr_f	p[10];
  int	ret;

  if (!cmd || !cmd[0])
    return (0);
  i = is_builtin(cmd[0]);
  if (i < 0)
    return (-1);
  builtin_create_ptr_func(p);
  ret = p[i](global, cmd);
  return (ret);
}
