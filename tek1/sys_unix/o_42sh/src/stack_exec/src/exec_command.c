/*
** exec_command.c for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 12 11:21:53 2012 ronan guiho
** Last update Sat Apr 28 17:22:19 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "sh.h"
#include "my.h"
#include "env.h"
#include "tree.h"
#include "token.h"
#include "execute.h"

static char		*exec_command_pathvar(char *cmd, t_env *env)
{
  int		i;
  struct stat   st;
  char		*path;
  char		**tab_path;

  i = -1;
  if ((tab_path = exec_create_tabvar_env(env, "PATH", ":")) == NULL)
    {
      fprintf(stderr, "%s: Command not found.\n", cmd);
      return (NULL);
    }
  while (tab_path[++i])
    {
      if ((path = my_strconcat("/", cmd)) == NULL)
	return (NULL);
      if ((path = my_strconcat(tab_path[i], path)) == NULL)
	return (NULL);
      if ((lstat(path, &st)) != -1)
	return (my_strconcat(tab_path[i], "/"));
      free(path);
    }
  my_free_tab(tab_path);
  if ((path = malloc(sizeof(char))) == NULL)
    return (NULL);
  path[0] = '\0';
  return (path);
}

static int		exec_command_check(char *cmd)
{
  struct stat   st;

  if ((access(cmd, F_OK)) == -1 || (exec_check_slash(cmd) == FALSE))
    {
      fprintf(stderr, "%s: Command not found.\n", cmd);
      return (EXIT_FAILURE);
    }
  if ((stat(cmd, &st)) == -1)
    return (EXIT_FAILURE);
  else
    {
      if ((access(cmd, X_OK)) == -1 || S_ISDIR(st.st_mode))
	{
	  fprintf(stderr, "%s: Permission denied.\n", cmd);
	  return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}

int		exec_command(t_node *master_node, t_env *env)
{
  char		*path;
  char		**tab_command;
  char		**tab_environ;

  path = NULL;
  if ((tab_command = exec_convert(master_node)) == NULL)
    return (EXIT_FAILURE);
  if ((tab_environ = export_env(env)) == NULL)
    {
      my_free_tab(tab_command);
      return (EXIT_CHILD);
    }
  if ((exec_check_slash(tab_command[0])) == FALSE)
    if ((path = exec_command_pathvar(tab_command[0], env)) == NULL)
      {
	my_free_tab(tab_environ);
	my_free_tab(tab_command);
	return (EXIT_CHILD);
      }
  if ((path = my_strconcat(path, tab_command[0])) == NULL)
    {
      my_free_tab(tab_environ);
      my_free_tab(tab_command);
      return (EXIT_FAILURE);
    }
  if ((exec_command_check(path)) == EXIT_FAILURE)
    {
      my_free_tab(tab_environ);
      my_free_tab(tab_command);
      return (EXIT_CHILD);
    }
  if ((execve(path, tab_command, tab_environ)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
