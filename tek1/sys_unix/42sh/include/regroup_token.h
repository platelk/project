/*
** regroup_token.h for regroup_token in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 14:58:19 2012 harold ozouf
** Last update Sat May 19 13:55:09 2012 zoe phalippou
*/

#ifndef		__REGROUP_TOKEN_H__
# define	__REGROUP_TOKEN_H__

#include	"token.h"

t_bool	regroup_red(t_token **, t_token **);
t_bool	regroup_quote(t_token **, t_token **);
t_bool	regroup_par(t_token **, t_token **);
t_bool	regroup_history(t_token **, t_token **);
t_bool	regroup_variable(t_token **, t_token **);
t_bool	regroup_inibit(t_token **, t_token **);
t_bool	regroup_esp(t_token **, t_token **);

#endif
