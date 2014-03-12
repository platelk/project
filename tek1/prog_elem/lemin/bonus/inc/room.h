/*
** room.h for hex in /home/leprov_a//depot/lemin/bonus/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr  2 14:32:37 2012 alexis leprovost
** Last update Wed Apr 11 16:03:41 2012 alexis leprovost
*/

#ifndef __ROOM_H__
#define __ROOM_H__

typedef enum s_status
{
  START,
  TMP,
  END,
  GRASS,
  ROAD,
  TREE,
  ROOM
} e_status;

typedef enum s_coord
{
  X,
  Y
} e_coord;

typedef struct s_room
{
  int	occ;
  int	status;
  int	pos[2];
  char	*name;
  int	weight;
  struct s_room **link;
  struct s_room *next;
} t_room;

#endif
