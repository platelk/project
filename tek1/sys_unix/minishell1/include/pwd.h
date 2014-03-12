/*
** pwd.h for pwd.h in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Dec 13 17:33:05 2011 kevin platel
** Last update Thu Dec 15 09:28:44 2011 kevin platel
*/

#ifndef __PWD_H_
#define __PWD_H_

typedef struct s_pwd
{
  char *name;
  struct s_pwd *next;
  struct s_pwd *prev;
} t_pwd;

#endif
