/*
** builtin_history_param.h for 42sh in /home/phalip_z//exos/projets/42sh/42sh_builtin_history
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue Apr 24 10:35:43 2012 zoe phalippou
** Last update Tue May  1 11:42:14 2012 zoe phalippou
*/

#ifndef	__BUILTIN_HISTORY_CREATE_PARAM_H__
# define __BUILTIN_HISTORY_CREATE_PARAM_H__

#include	"t_history.h"

typedef	int	(*ptr_f_built_history)(char **, t_history **);

char			**create_args_history(void);
ptr_f_built_history	*create_ptr_built_history(ptr_f_built_history *);

#endif
