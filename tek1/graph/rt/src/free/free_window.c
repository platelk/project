/*
** free_window.c for raytracer in /home/leprov_a//depot/rt/src/free
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 10:27:04 2012 alexis leprovost
** Last update Tue May  8 10:50:00 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"window.h"
#include	"free.h"

void	free_window(t_window *window)
{
  if (window)
    {
      free_image(window->background);
      free(window);
    }
}
