/*
** edge.c for vm in /home/leprov_a//depot/corewar/source/VM/graph
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar  9 12:39:56 2012 alexis leprovost
** Last update Tue Mar 13 10:16:24 2012 alexis leprovost
*/

#include        <stdlib.h>
#include	<unistd.h>

#include        "vm.h"
#include        "corewar.h"

void	run_vertical(int indice, t_image **anim, t_image **image,
		     SDL_Surface *sc)
{
  int	y;
  int	xe;

  y = -1 + indice;
  xe = (X_WIN / BLOC_ANIM) - indice;
  while (++y <= ((Y_WIN / BLOC_ANIM) - indice))
    {
      if (!image)
        {
          SDL_FillRect(anim[y][indice].img, NULL,
		       SDL_MapRGB(anim[y][indice].img->format, 0, 0, 0));
          SDL_BlitSurface(anim[y][indice].img, NULL, sc, &anim[y][indice].pos);
	  SDL_FillRect(anim[y][xe].img, NULL,
		       SDL_MapRGB(anim[y][xe].img->format, 0, 0, 0));
          SDL_BlitSurface(anim[y][xe].img, NULL, sc, &anim[y][xe].pos);
        }
      else
	{
	  SDL_BlitSurface(image[GAME][BACK].img, &anim[y][indice].pos, sc,
			  &anim[y][indice].pos);
	  SDL_BlitSurface(image[GAME][BACK].img, &anim[y][xe].pos, sc,
			  &anim[y][xe].pos);
	}
    }
}

void	run_horizontal(int indice, t_image **anim, t_image **image,
		     SDL_Surface *sc)
{
  int	x;
  int	ye;

  x = -1 + indice;
  ye = (Y_WIN / BLOC_ANIM) - indice;
  while (++x <= ((X_WIN / BLOC_ANIM) - indice))
    {
      if (!image)
        {
          SDL_FillRect(anim[indice][x].img, NULL,
		       SDL_MapRGB(anim[indice][x].img->format, 0, 0, 0));
          SDL_BlitSurface(anim[indice][x].img, NULL, sc, &anim[indice][x].pos);
	  SDL_FillRect(anim[ye][x].img, NULL,
		       SDL_MapRGB(anim[ye][x].img->format, 0, 0, 0));
          SDL_BlitSurface(anim[ye][x].img, NULL, sc, &anim[ye][x].pos);
        }
      else
	{
	  SDL_BlitSurface(image[GAME][BACK].img, &anim[indice][x].pos, sc,
			  &anim[indice][x].pos);
	  SDL_BlitSurface(image[GAME][BACK].img, &anim[ye][x].pos, sc,
			  &anim[ye][x].pos);
	}
    }
}

void    run_edge(int indice, t_image **anim, t_image **image, SDL_Surface *sc)
{
  run_horizontal(indice, anim, image, sc);
  run_vertical(indice, anim, image, sc);
  usleep(100000);
  SDL_Flip(sc);
}

void	edge_anim(t_image **anim, SDL_Surface *sc, t_image **image)
{
  int	i;

  i = -1;
  while (++i <= (Y_WIN / BLOC_ANIM))
    run_edge(i, anim, NULL, sc);
  while (--i >= 0)
    run_edge(i, anim, image, sc);
}
