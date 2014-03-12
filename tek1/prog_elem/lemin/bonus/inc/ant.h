/*
** ant.h for hex in /home/leprov_a//depot/lemin/bonus/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr  2 14:31:04 2012 alexis leprovost
** Last update Wed Apr  4 10:46:17 2012 alexis leprovost
*/

#ifndef __ANT_H__
#define __ANT_H__

#include	"room.h"

typedef struct s_ant
{
  t_room *current_room;
  t_room *old_room;
} t_ant;

#endif
