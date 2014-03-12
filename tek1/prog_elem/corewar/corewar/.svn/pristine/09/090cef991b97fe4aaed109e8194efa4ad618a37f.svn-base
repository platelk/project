/*
** display_animation.c for vm in /home/leprov_a//depot/corewar/source/VM/graph
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Mar  8 11:15:29 2012 alexis leprovost
** Last update Sun Mar 25 03:23:11 2012 ronan guiho
*/

#include	<stdlib.h>

#include	"vm.h"
#include	"corewar.h"

t_image	**init_anim(void)
{
  t_image	**anim;
  int		value[4];

  value[3] = 0;
  value[0] = -1;
  if ((anim = malloc(sizeof(*anim) * ((Y_WIN / BLOC_ANIM) + 1))) == NULL)
    return (NULL);
  while (++value[0] <= (Y_WIN / BLOC_ANIM))
    {
      value[1] = -1;
      value[2] = 0;
      if ((anim[value[0]] = malloc(sizeof(**anim) * ((X_WIN / BLOC_ANIM)
					      + 1))) == NULL)
	return (NULL);
      while (++value[1] <= (X_WIN / BLOC_ANIM))
	{
	  anim[value[0]][value[1]].img = SDL_CreateRGBSurface \
	    (SDL_HWSURFACE, BLOC_ANIM, BLOC_ANIM, 32, 0, 0, 0, 0);
	  anim[value[0]][value[1]].pos.x = value[2];
	  anim[value[0]][value[1]].pos.y = value[3];
	  value[2] += BLOC_ANIM;
	}
      value[3] += BLOC_ANIM;
    }
  return (anim);
}

int	display_animation(SDL_Surface *sc, t_image **image)
{
  t_image	**anim;
  void	(*func_anim[NB_ANIM_MAX])(t_image **, SDL_Surface *, t_image **);
  int	c;

  func_anim[WAWE] = &wawe_anim;
  func_anim[MIST] = &mist_anim;
  func_anim[SPIRAL] = &spiral_anim;
  func_anim[EDGE] = &edge_anim;
  c = get_rand_number(NB_ANIM_MAX);
  if ((anim = init_anim()) == NULL)
    return (EXIT_FAILURE);
  func_anim[c](anim, sc, image);
  return (EXIT_SUCCESS);
}
