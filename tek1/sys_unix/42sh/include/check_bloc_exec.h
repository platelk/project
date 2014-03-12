/*
** check_bloc_exec.h for check_bloc_exec in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 22:58:27 2012 harold ozouf
** Last update Sat May 19 13:48:11 2012 zoe phalippou
*/

#ifndef		__CHECK_BLOC_EXEC_H__
# define	__CHECK_BLOC_EXEC_H__

#include	"tree.h"
#include	"token.h"

t_bool	there_are_two_red(t_token *, t_token *);
void	get_pre_exec(t_token *, t_token **, t_token **, t_token **);
t_bool	check_bloc_exec(t_token *, t_token *, t_node **);

#endif
