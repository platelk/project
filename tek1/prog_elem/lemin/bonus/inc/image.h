/*
** image.h for hex in /home/leprov_a//depot/lemin/bonus/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Apr  6 17:55:56 2012 alexis leprovost
** Last update Wed Apr 11 14:21:44 2012 alexis leprovost
*/

#ifndef __IMAGE_H__
#define __IMAGE_H__

#include	<SDL/SDL.h>

typedef enum e_side
{
  NORTH,
  WEST,
  SOUTH,
  EAST
} t_side;

typedef struct s_image
{
  SDL_Surface	*image;
  SDL_Rect	pos;
} t_image;

#endif
