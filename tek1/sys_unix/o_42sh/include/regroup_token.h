/*
** regroup_token.h for regroup_token in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 14:58:19 2012 harold ozouf
** Last update Thu Apr 12 16:48:15 2012 harold ozouf
*/

#ifndef		__REGROUP_TOKEN_H__
# define	__REGROUP_TOKEN_H__

#include	"token.h"

t_bool	regroup_red(t_token **r, t_token **o);
t_bool	regroup_quote(t_token **r, t_token **o);
t_bool	regroup_par(t_token **r, t_token **o);
t_bool	regroup_history(t_token **r, t_token **o);
t_bool	regroup_variable(t_token **r, t_token **o);
t_bool	regroup_inibit(t_token **r, t_token **o);

#endif
