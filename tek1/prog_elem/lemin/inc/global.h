/*
** global.h for lemin in /home/guiho_r/tek1/lemin/inc
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr  4 10:07:41 2012 ronan guiho
** Last update Mon Apr  9 15:21:54 2012 kevin platel
*/

#ifndef	__GLOBAL_H__
#define	__GLOBAL_H__

#include "ant.h"
#include "room.h"

typedef struct s_glob
{
  t_room       *room;
  t_ant	       **ant;
  int	       nb_ant;
}t_glob;

#endif
