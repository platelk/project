/*
** move.h for hex in /home/leprov_a//depot/lemin/bonus/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr  2 14:38:53 2012 alexis leprovost
** Last update Wed Apr  4 11:17:17 2012 alexis leprovost
*/

#ifndef __MOVE_H__
#define __MOVE_H__

typedef struct s_move
{
  char **current_move;
  struct s_move *next;
  struct s_move *before;
} t_move;

#endif
