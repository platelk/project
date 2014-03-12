/*
** history_showlist.h for 42sh in /home/phalip_z//exos/projets/42sh/42sh_builtin_history
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue May  1 14:38:26 2012 zoe phalippou
** Last update Tue May  1 17:52:23 2012 zoe phalippou
*/

#ifndef	__HISTORY_SHOWLIST_H__
# define __HISTORY_SHOWLIST_H__

#include	"t_history.h"

void	show_param_history(t_history *);
void	show_history(t_history *, int);
int	put_error(char *);

#endif
