/*
** exec_create_tabenv_var.c for stack_exec in /home/guiho_r/tek1/42sh/src/env/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 12 14:56:14 2012 ronan guiho
** Last update Sat Apr 28 17:11:44 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "env.h"

char	**exec_create_tabvar_env(t_env *env, char *var, char *delim)
{
  char	*buffer;
  char	**tab_buffer;

  if ((buffer = find_in_env(var, env)) == NULL)
    return (NULL);
  if ((tab_buffer = my_strtok(buffer, delim, TOK_DELIM)) == NULL)
    return (NULL);
  return (tab_buffer);
}
