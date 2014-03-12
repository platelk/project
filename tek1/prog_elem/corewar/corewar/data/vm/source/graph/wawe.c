/*
** wawe.c for vm in /home/leprov_a//depot/corewar/source/VM/graph
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar  9 12:31:50 2012 alexis leprovost
** Last update Tue Mar 13 10:16:00 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"vm.h"
#include	"corewar.h"

void	wawe_anim(t_image **anim, SDL_Surface *sc, t_image **image)
{
  int	i;
  int	k;

  i = -1;
  while (++i <= (Y_WIN / BLOC_ANIM))
    {
      k = -1;
      while (++k <= (X_WIN / BLOC_ANIM))
	{
	  SDL_FillRect(anim[i][k].img, NULL, SDL_MapRGB(anim[i][k].img->format,
							0, 0, 0));
	  SDL_BlitSurface(anim[i][k].img, NULL, sc, &anim[i][k].pos);
	  SDL_Flip(sc);
	}
    }
  while (--i >= 0)
    {
      k = (X_WIN / BLOC_ANIM) + 1;
      while (--k >= 0)
	{
	  SDL_BlitSurface(image[GAME][BACK].img, &anim[i][k].pos, sc,
			  &anim[i][k].pos);
	  SDL_Flip(sc);
	}
    }
}
