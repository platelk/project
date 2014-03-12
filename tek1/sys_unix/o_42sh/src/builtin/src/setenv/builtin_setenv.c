/*
** builtin_setenv.c for 42sh in /home/phalip_z//exos/projets/42sh/42sh_builtin_setenv
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Wed Apr 11 17:10:05 2012 zoe phalippou
** Last update Thu Apr 26 14:48:16 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"my.h"
#include	"xsys.h"
#include	"global.h"

void	create_variable(t_env **env, char *name, char *value)
{
  t_env	*new;
  t_env *tmp;

  tmp = *env;
  new = xmalloc(sizeof(*new));
  new->name = my_strdup(name);
  if (value == NULL)
    new->value = my_strdup("\0");
  else
    new->value = my_strdup(value);
  new->next = NULL;
  new->prev = NULL;
  if (*env != NULL)
    {
      while ((*env)->next != NULL)
	(*env) = (*env)->next;
      (*env)->next = new;
      new->prev = *env;
      *env = tmp;
    }
  else
    *env = new;
 }

void	change_variable(t_env *env, char *name, char *value)
{
  name = name;
 if (env->value)
    free(env->value);
  if (value == NULL)
    env->value = my_strdup("\0");
  else
    env->value = my_strdup(value);
}

void	check_exist_or_not(t_env **env, char *name, char *value)
{
  t_env	*tmp;

  tmp = *env;
  while (tmp != NULL && my_strncmp(name, tmp->name, strlen(tmp->name)) != 0)
    tmp = tmp->next;
  if (tmp == NULL)
    create_variable(env, name, value);
  else
    change_variable(tmp, name, value);
}

int	check_setenv(t_global *global, char **cmd)
{
  if (cmd[1] == NULL)
    print_env(global->env);
  else if (cmd[1] != NULL || (cmd[1] != NULL && cmd[2] != NULL))
    check_exist_or_not(&global->env, cmd[1], cmd[2]);
  else
    {
      fprintf(stderr, "%s: Too many arguments.\n", cmd[0]);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
