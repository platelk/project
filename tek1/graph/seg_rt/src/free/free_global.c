/*
** free_global.c for raytracer in /home/leprov_a//depot/rt/src/free
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 10:25:02 2012 alexis leprovost
** Last update Wed May  2 18:42:18 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"global.h"
#include	"free.h"

void	free_global(t_global *global)
{
  if (global)
    {
      free_window(global->window);
    }
}
