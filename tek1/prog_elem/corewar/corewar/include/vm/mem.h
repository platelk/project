/*
** mem.h for mem.h in /home/leprov_a//depot/corewar/include
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Feb  9 14:18:06 2012 alexis leprovost
** Last update Tue Mar 20 17:20:57 2012 alexis leprovost
*/

#ifndef	__MEM_H__
#define __MEM_H__

#include <SDL/SDL.h>

typedef	enum
{
  NONE,
  WRITE,
  READ,
  LIVES,
  ACTIF
}e_mem;

typedef	struct	s_mem
{
  int		indice;
  int		value;
  int		id;
  int		state;
  int		*color;
  SDL_Rect	p;
  struct	s_mem	*next;
  struct	s_mem	*before;
}t_mem;

#endif
