/*
** check_cmd.h for check_cmd in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat Apr 14 23:40:02 2012 harold ozouf
** Last update Tue Apr 17 18:34:00 2012 harold ozouf
*/

#ifndef		__CHECK_CMD_H__
# define	__CHECK_CMD_H__

#include	"token.h"
#include	"tree.h"

t_bool	check_cmd(t_token *b, t_token *e, t_node **root);

#endif
