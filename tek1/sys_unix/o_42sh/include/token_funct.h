/*
** token_funct.h for token_funct in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Apr 10 15:44:58 2012 harold ozouf
** Last update Thu Apr 12 18:24:41 2012 harold ozouf
*/

#ifndef		__TOKEN_FUNCT_H__
# define	__TOKEN_FUNCT_H__

#include	"token.h"

t_bool	is_an_excla(t_token **tok, char **str);
t_bool	is_a_word(t_token **tok, char **str);
t_bool	is_a_quote(t_token **tok, char **str);
t_bool	is_a_pv(t_token **tok, char **str);
t_bool	is_an_oper_cond(t_token **tok, char **str);
t_bool	is_a_esp(t_token **tok, char **str);
t_bool	is_a_par(t_token **tok, char **str);
t_bool	is_a_red_s(t_token **tok, char **str);
t_bool	is_a_red_d(t_token **tok, char **str);
t_bool	is_a_dollar(t_token **tok, char **str);
t_bool	is_a_spacer(t_token **tok, char **str);
t_bool	is_an_alphanum(char **str);
t_bool	is_a_inibited_char(t_token **tok, char **str);

#endif
