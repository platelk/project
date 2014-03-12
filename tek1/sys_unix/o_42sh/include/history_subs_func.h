/*
** subs_func_history.h for 42sh in /home/phalip_z//exos/projets/42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue Apr 10 17:02:04 2012 zoe phalippou
** Last update Wed Apr 18 20:44:51 2012 zoe phalippou
*/

#ifndef	__HISTORY_SUBS_FUNC_H__
# define __HISTORY_SUBS_FUNC_H__

#include	"t_history.h"

char	*subs_interogation_mark(char *, t_history *);
char	*subs_exclamation_mark(char *, t_history *);
char	*subs_letter(char *, t_history *);
char	*subs_nbr(char *, t_history *);
char	*subs_back_in_history(char *, t_history *);

#endif
