/*
** node.h for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 12 10:26:28 2012 ronan guiho
** Last update Fri Apr 13 15:51:11 2012 ronan guiho
*/

#ifndef	__NODE_H__
#define __NODE_H__

#include "token.h"
#include "child.h"

typedef struct		s_node
{
  enum e_token		id;
  char			*content;
  struct s_child	*child;
} t_node;

#endif
