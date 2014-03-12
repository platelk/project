/*
** global.h for 42sh in /home/leprov_a//depot/42sh/include
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 18 17:15:12 2012 alexis leprovost
** Last update Mon Apr 30 10:21:30 2012 ronan guiho
*/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include	"config.h"
#include	"env.h"
#include	"t_history.h"
#include	"get_next_line.h"

typedef struct s_global
{
  t_config	*config;
  t_history	*hist;
  t_env		*env;
  t_line	*data;
  char		*prompt;
  int		curser;
  int		status;
} t_global;

#endif
