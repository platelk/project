/*
** exec_command_pathvar.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May 18 12:26:54 2012 ronan guiho
** Last update Fri May 18 14:29:15 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "execute.h"

char		*exec_command_pathvar_none(char **tab_path)
{
  char		*path;

  if (tab_path != NULL)
  my_free_tab(tab_path);
  if ((path = malloc(sizeof(char))) == NULL)
    return (NULL);
  path[0] = '\0';
  return (path);
}
