/*
** history_create_ptr_func.h for history in /home/vink/projet/sys_unix/42sh
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Fri May 18 18:43:29 2012 kevin platel
** Last update Fri May 18 18:43:32 2012 kevin platel
*/

#ifndef	__HISTORY_CREATE_PTR_FUNC_H__
#define __HISTORY_CREATE_PTR_FUNC_H__

#include	"t_history.h"

typedef char	*(*ptr_f_history)(char *, t_history *);

char		**put_str_subs(void);
ptr_f_history	*create_ptr_func_history(ptr_f_history *);

#endif
