/*
** history_create_list.h for 42sh in /home/phalip_z//42sh/src/builtin/src/history
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Wed May  9 18:21:52 2012 zoe phalippou
** Last update Sat May 19 15:35:30 2012 zoe phalippou
*/

#ifndef __HISTORY_CREATE_LIST_H__
# define __HISTORY_CREATE_LIST_H__

#include	"global.h"

t_history	*history_create_list(t_config *, t_history **);
int		history_file_config(t_config *, t_history *);
t_history	*history_list_config(t_config *, t_history *, int);

#endif
