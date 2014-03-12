/*
** builtin.h for 42sh in /home/vink/projet/sys_unix/42sh/src/builtin/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Apr 13 12:49:20 2012 kevin platel
** Last update Tue May  1 17:06:33 2012 zoe phalippou
*/

#ifndef __BUILTIN_H__
#define __BUILTIN_H__

#include	"env.h"
#include	"global.h"

typedef	int	(*builtin_ptr_f)(t_global *, char **);

builtin_ptr_f	*builtin_create_ptr_func(builtin_ptr_f *p);
int	builtin_ptr_func(char **cmd, t_global *global);
char	*search_in_tab(char *str, char **tab);
int	is_builtin(char *str);
int	echo(t_global *global, char **av);
int     check_setenv(t_global *global, char **cmd);
int     check_unsetenv(t_global *global, char **cmd);
int     check_history(t_global *global, char **cmd);
int	cd(t_global *global, char **cmd);
void    create_variable(t_env **env, char *name, char *value);
void    change_variable(t_env *env, char *name, char *value);
void    check_exist_or_not(t_env **env, char *name, char *value);
int	builtin_exit(t_global *g, char **cmd);

#endif
