/*
** spiral.c for vm in /home/leprov_a//depot/corewar/source/VM/graph
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar  9 12:29:31 2012 alexis leprovost
** Last update Fri Mar  9 12:30:05 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"vm.h"
#include	"corewar.h"

void	run_down(int indice, t_image **anim, t_image **image, SDL_Surface *sc)
{
  int	k;
  int	i;

  k = indice;
  i = -1;
  while (++i <= (Y_WIN / BLOC_ANIM))
    {
      if (!image)
	{
	  SDL_FillRect(anim[i][k].img, NULL, SDL_MapRGB(anim[i][k].img->format,
							0, 0, 0));
	  SDL_BlitSurface(anim[i][k].img, NULL, sc, &anim[i][k].pos);
	}
      else
	SDL_BlitSurface(image[GAME][BACK].img, &anim[i][k].pos, sc,
			&anim[i][k].pos);
	SDL_Flip(sc);
    }
}

void	run_up(int indice, t_image **anim, t_image **image, SDL_Surface *sc)
{
  int	k;
  int	i;

  k = indice;
  i = (Y_WIN / BLOC_ANIM) + 1;
  while (--i >= 0)
    {
      if (!image)
	{
	  SDL_FillRect(anim[i][k].img, NULL, SDL_MapRGB(anim[i][k].img->format,
							0, 0, 0));
	  SDL_BlitSurface(anim[i][k].img, NULL, sc, &anim[i][k].pos);
	}
      else
	SDL_BlitSurface(image[GAME][BACK].img, &anim[i][k].pos, sc,
			&anim[i][k].pos);
	SDL_Flip(sc);
    }
}

void	run_left(int indice, t_image **anim, t_image **image, SDL_Surface *sc)
{
  int	k;
  int	i;

  i = indice;
  k = (X_WIN / BLOC_ANIM) + 1;
  while (--k >= 0)
    {
      if (!image)
	{
	  SDL_FillRect(anim[i][k].img, NULL, SDL_MapRGB(anim[i][k].img->format,
							0, 0, 0));
	  SDL_BlitSurface(anim[i][k].img, NULL, sc, &anim[i][k].pos);
	}
      else
	SDL_BlitSurface(image[GAME][BACK].img, &anim[i][k].pos, sc,
			&anim[i][k].pos);
	SDL_Flip(sc);
    }
}

void	run_right(int indice, t_image **anim, t_image **image, SDL_Surface *sc)
{
  int	k;
  int	i;

  i = indice;
  k = -1;
  while (++k <= (X_WIN / BLOC_ANIM))
    {
      if (!image)
	{
	  SDL_FillRect(anim[i][k].img, NULL, SDL_MapRGB(anim[i][k].img->format,
							0, 0, 0));
	  SDL_BlitSurface(anim[i][k].img, NULL, sc, &anim[i][k].pos);
	}
      else
	SDL_BlitSurface(image[GAME][BACK].img, &anim[i][k].pos, sc,
			&anim[i][k].pos);
	SDL_Flip(sc);
    }
}

void	spiral_anim(t_image **anim, SDL_Surface *sc, t_image **image)
{
  int	i;

  i = -1;
  while (++i <= (Y_WIN / BLOC_ANIM))
    {
      run_right(i, anim, NULL, sc);
      run_down((X_WIN / BLOC_ANIM) - i, anim, NULL, sc);
      run_left((Y_WIN / BLOC_ANIM) - i, anim, NULL, sc);
      run_up(i, anim, NULL, sc);
    }
  i = -1;
  while (++i <= (Y_WIN / BLOC_ANIM))
    {
      run_left((Y_WIN / BLOC_ANIM) - i, anim, image, sc);
      run_up(i, anim, image, sc);
      run_right(i, anim, image, sc);
      run_down((X_WIN / BLOC_ANIM) - i, anim, image, sc);
    }
}
