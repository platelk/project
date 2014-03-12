/*
** global.h for 42sh in /home/leprov_a//depot/42sh/include
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 18 17:15:12 2012 alexis leprovost
** Last update Thu May 17 16:12:15 2012 alexis leprovost
*/

#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#include	"config.h"
#include	"env.h"
#include	"t_history.h"
#include	"get_next_line.h"

typedef enum s_motion
{
  X,
  Y
} t_motion;

typedef struct s_global
{
  t_config	*config;
  t_history	*hist;
  t_env		*env;
  t_line	*data;
  char		*prompt;
  int		len;
  int		curser[2];
  int		dom[2];
  int		status;
  int		exit;
  int		echo;
  int		ctrlc;
} t_global;

#endif
