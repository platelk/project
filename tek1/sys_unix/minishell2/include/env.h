/*
** env.h for env in /home/platel_k/projet/minishell1/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Dec 13 11:23:07 2011 kevin platel
** Last update Wed Apr 11 10:06:19 2012 kevin platel
*/

#ifndef __ENV_H_
#define __ENV_H_

typedef struct s_env
{
  char	*name;
  char	*content;
  struct s_env *next;
  struct s_env *prev;
} t_env;

#endif
