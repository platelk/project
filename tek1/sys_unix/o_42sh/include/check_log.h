/*
** check_log.h for check_log in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 20:53:37 2012 harold ozouf
** Last update Tue Apr 17 18:34:23 2012 harold ozouf
*/

#ifndef		__CHECK_LOG_H__
# define	__CHECK_LOG_H__

#include	"token.h"
#include	"tree.h"

t_bool	check_log(t_token *begin, t_token *end, t_node **root, int flag);

#endif
