/*
** history.h for history in /home/platel_k/projet/sys_unix/minishell2/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Jan 31 13:11:20 2012 kevin platel
** Last update Tue Jan 31 13:12:40 2012 kevin platel
*/

#ifndef __HISTORY_H__
#define __HISTORY_H__

typedef struct s_hist
{
  char	*cmd;
  struct s_hist	*next;
  struct s_hist	*prev;
} t_hist;
