/*
** pipe.h for stack_exec in /home/guiho_r/tek1/42sh/src/stack_exec/src/pipe
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Apr 15 17:58:28 2012 ronan guiho
** Last update Mon Apr 16 12:51:33 2012 ronan guiho
*/

#ifndef	__PIPE_H__
#define __PIPE_H__

typedef enum s_state_pipe
{
  INIT,
  NONE_STATE
} t_state_pipe;

typedef enum s_entry
{
  STDIN,
  STDOUT
} t_entry;

typedef enum s_state_action
{
  READ,
  WRITE
} s_state_action;

#endif
