/*
** child.h for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 12 10:23:40 2012 ronan guiho
** Last update Thu Apr 12 10:38:26 2012 ronan guiho
*/

#ifndef	__CHILD_H__
#define __CHILD_H__

#include "node.h"
#include "token.h"

typedef struct		s_child
{
  struct s_node		*nd;
  struct s_child	*next;
} t_child;

#endif
