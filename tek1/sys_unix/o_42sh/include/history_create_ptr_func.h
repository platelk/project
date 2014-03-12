/*
** create_ptr_func_history.h for 42sh in /home/phalip_z//exos/projets/42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue Apr 10 17:54:59 2012 zoe phalippou
*/

#ifndef	__HISTORY_CREATE_PTR_FUNC_H__
# define __HISTORY_CREATE_PTR_FUNC_H__

#include	"t_history.h"

typedef char	*(*ptr_f_history)(char *, t_history *);

char		**put_str_subs(void);
ptr_f_history	*create_ptr_func_history(ptr_f_history *);

#endif
