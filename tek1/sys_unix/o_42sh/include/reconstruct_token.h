/*
** reconstruct_token.h for reconstruct_token in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 16:00:56 2012 harold ozouf
** Last update Wed Apr 11 18:29:45 2012 harold ozouf
*/

#ifndef		__RECONSTRUCT_TOKEN_H__
# define	__RECONSTRUCT_TOKEN_H__

#include	"token.h"

void		change_token_exec(t_token **tok);
f_regroup	*init_ptr_funct_regroup(void);
t_bool		re_add_token(t_token **root, t_token **tok);
t_token		*reconstruct_token(t_token *tok);

#endif
