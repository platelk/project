/*
** builtin_unsetenv.c for 42sh in /home/phalip_z//exos/projets/42sh/42sh_builtin_unsetenv
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Wed Apr 11 15:55:44 2012 zoe phalippou
** Last update Fri May 18 18:34:29 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"edit.h"
#include	"global.h"

static void	remove_var(t_env **env)
{
  t_env	*tmp;

  tmp = *env;
  if (tmp->next && tmp->prev)
    {
      tmp->prev->next = tmp->next;
      tmp->next->prev = tmp->prev;
    }
  else if (tmp->prev)
    tmp->prev->next = NULL;
  if (tmp->name)
    free(tmp->name);
  if (tmp->value)
    free(tmp->value);
  free(tmp);
}

static int	exec_unsetenv(char *arg, t_env **env)
{
  t_env	*tmp;

  tmp = *env;
  while (tmp)
    {
      if (!strncmp(arg, tmp->name, strlen(tmp->name)))
	{
	  if (!tmp->prev)
	    {
	      free(tmp->name);
	      if (tmp->value)
		free(tmp->value);
	      *env = tmp->next;
	      free(tmp);
	      tmp = *env;
	      if (*env)
		(*env)->prev = NULL;
	    }
	  else
	    remove_var(&tmp);
	  return (EXIT_SUCCESS);
	}
      tmp = tmp->next;
    }
  return (EXIT_FAILURE);
}

int	check_unsetenv(t_global *global, char **cmd)
{
  int	i;

  i = 0;
  if (cmd[1] == NULL)
    {
      fprintf(stderr, "%s: Too few arguments.\n", cmd[0]);
      return (EXIT_FAILURE);
    }
  else
    while (cmd[++i])
      {
	if (exec_unsetenv(cmd[i], &global->env))
	  fprintf(stderr, "Variable %s doesn't exist\n", cmd[i]);
	else
	  printf("Variable %s has removed successfully.\n", cmd[i]);
      }
  edit_env(global->config, &(global->env));
  return (EXIT_SUCCESS);
}
