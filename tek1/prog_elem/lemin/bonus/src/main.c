/*
** main.c for hex in /home/leprov_a//depot/lemin/bonus
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr  2 14:26:50 2012 alexis leprovost
** Last update Wed Apr 11 16:00:36 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<SDL/SDL.h>

#include	"hex.h"

void	aff_tmp(char **map)
{
  int	i;
  int	k;

  i = -1;
  while (++i < (X_WIN / STEP))
    {
      k = -1;
      while (++k < (Y_WIN / STEP))
	my_putchar(map[i][k] + 48);
      my_putchar('\n');
    }
}

int	main(void)
{
  t_glob	*glob;
  t_bool	status;
  char	**map;

  status = TRUE;
  if ((glob = parser_main()) == NULL ||
      (map = get_world(glob->room)) == NULL)
    return (EXIT_FAILURE);
  if ((SDL_Init(SDL_INIT_VIDEO)) == -1 ||
      (glob->window = SDL_SetVideoMode(X_WIN, Y_WIN, 32,
				       SDL_HWSURFACE | SDL_DOUBLEBUF)) == NULL)
    return (my_puterror("Error: missing variable DISPLAY.\n"));
  SDL_WM_SetCaption("~ HEX ~", NULL);
  aff_tmp(map);
  SDL_Quit();
  return (EXIT_SUCCESS);
}
