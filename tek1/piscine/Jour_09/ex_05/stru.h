/*
** stru.h for stru.h in /home/platel_k//projet/piscine/Jour_09/ex_03
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct 13 11:52:30 2011 kevin platel
** Last update Thu Oct 13 11:59:55 2011 kevin platel
*/

#ifndef __STRU_H__
#define __STRU_H__


struct s_stock_par
{
  int	size_param;
  char	*str;
  char	*copy;
  char	**tab;
};

typedef struct s_stock_par t_stock_par;

#endif
