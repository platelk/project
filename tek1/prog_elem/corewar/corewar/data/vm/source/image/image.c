/*
** image.c for corewar in /home/guiho_r/tek1/corewar/source/VM/image
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Mar  7 18:15:35 2012 ronan guiho
** Last update Sun Mar 25 03:05:41 2012 ronan guiho
*/

#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

t_image		**init_image()
{
  t_image	**image_tab;

  if ((image_tab = malloc(sizeof(t_image *) * NB_IMAGE_TYPE_MAX)) == NULL)
    return (NULL);
  if ((image_tab[MENU_IMG] = init_image_el(PATH_IMAGE_MENU,
					   NB_IMAGE_MENU_MAX)) == NULL)
    return (NULL);
  if ((image_tab[GAME] = init_image_el(PATH_IMAGE_GAME,
				       NB_IMAGE_GAME_MAX)) == NULL)
    return (NULL);
  if ((image_tab[CHARACT] = init_image_el(PATH_IMAGE_CHARACT,
					  NB_IMAGE_CHARACT_MAX)) == NULL)
    return (NULL);
  return (image_tab);
}
