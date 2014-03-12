/*
** dep.h for dep in /home/platel_k/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  1 12:59:21 2012 kevin platel
** Last update Wed Feb  1 13:01:14 2012 kevin platel
*/

#ifndef __DEP_H__
#define __DEP_H__

#include "data.h"

typedef struct s_dependence
{
  t_data	*data;
  struct s_dependence *next;
  struct s_dependence *prev;
} t_dependence;
