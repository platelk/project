/*
** cmd.h for cmd.h in /home/platel_k/projet/sys_unix/minishell2/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Jan 31 13:09:21 2012 kevin platel
** Last update Mon Feb 13 22:24:38 2012 kevin platel
*/

#ifndef	__CMD_H__
#define __CMD_H__

typedef struct s_cmd
{
  char	*cmd;
  int	sep;
  int	pipefd[2];
  struct s_cmd	*next;
  struct s_cmd	*prev;
} t_cmd;

#endif
