/*
** mist.c for vm in /home/leprov_a//depot/corewar/source/VM/graph
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar  9 12:30:42 2012 alexis leprovost
** Last update Tue Mar 13 10:16:18 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"vm.h"
#include	"corewar.h"

void	mist_anim(t_image **anim, SDL_Surface *sc, t_image **image)
{
  int	k;
  int	i;
  int	n;

  n = -1;
  while (++n < EPSILON)
    {
      k = get_rand_number((X_WIN / BLOC_ANIM) + 1);
      i = get_rand_number((Y_WIN / BLOC_ANIM) + 1);
      SDL_FillRect(anim[i][k].img, NULL, SDL_MapRGB(anim[i][k].img->format,
						    0, 0, 0));
      SDL_BlitSurface(anim[i][k].img, NULL, sc, &anim[i][k].pos);
      SDL_Flip(sc);
    }
  while (--n > 0)
    {
      k = get_rand_number((X_WIN / BLOC_ANIM) + 1);
      i = get_rand_number((Y_WIN / BLOC_ANIM) + 1);
      SDL_BlitSurface(image[GAME][BACK].img, &anim[i][k].pos, sc,
		      &anim[i][k].pos);
      SDL_Flip(sc);
    }
}
