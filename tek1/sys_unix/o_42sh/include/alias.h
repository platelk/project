/*
** alias.h for 42sh in /home/leprov_a//depot/42sh/src/config/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 00:23:23 2012 alexis leprovost
** Last update Thu Apr 26 18:20:46 2012 kevin platel
*/

#ifndef __ALIAS_H__
#define __ALIAS_H__

typedef struct s_alias
{
  char	*initial;
  char	*alias;
  int	flag;
  struct s_alias *next;
} t_alias;

#endif
