/*
** builtin.h for 42sh in /home/vink/projet/sys_unix/42sh/src/builtin/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Apr 13 12:49:20 2012 kevin platel
** Last update Sat May 19 13:03:15 2012 zoe phalippou
*/

#ifndef __BUILTIN_H__
#define __BUILTIN_H__

#include	"env.h"
#include	"global.h"

typedef	int	(*builtin_ptr_f)(t_global *, char **);

builtin_ptr_f	*builtin_create_ptr_func(builtin_ptr_f *);
int		builtin_ptr_func(char **, t_global *);
char		*search_in_tab(char *, char **);
int		is_builtin(char *);
int		echo(t_global *, char **);
int		check_setenv(t_global *, char **);
int		check_unsetenv(t_global *, char **);
int		check_history(t_global *, char **);
int		cd(t_global *, char **);
void		create_variable(t_env **, char *, char *);
void		change_variable(t_env *, char *, char *);
void		check_exist_or_not(t_env **, char *, char *);
int		builtin_exit(t_global *, char **);
int		builtin_unalias(t_global *, char **);
int		builtin_alias(t_global *, char **);

#endif
