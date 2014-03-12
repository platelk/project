/*
** my_rev_list.h for my_rev_list in /home/ozouf_h//42sh_local/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 18:39:39 2012 harold ozouf
** Last update Wed Apr 11 18:40:42 2012 harold ozouf
*/

#ifndef		__MY_REV_LIST_H__
# define	__MY_REV_LIST_H__

#include	"token.h"

int             my_list_sizes(t_token *begin);
t_token		*getnode(t_token *list, int n);
int		my_rev_list(t_token **begin);

#endif
