/*
** init_image.c for raytracer in /home/leprov_a//depot/rt/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue May  1 20:47:29 2012 alexis leprovost
** Last update Wed May 30 18:48:09 2012 ronan guiho
*/

#include        <stdio.h>
#include	<stdlib.h>

#include	"image.h"
#include	"mlx.h"
#include	"my.h"

t_image	*init_image(void *mlx_ptr, char *path, int x, int y)
{
  t_image	*image;

  /*if (path != NULL)
    {
      if ((image = import_bmp(mlx_ptr, path)) == NULL)
	return (NULL);
      return (image);
    }*/
  if (mlx_ptr == NULL)
    return (NULL);
  if ((image = malloc(sizeof(*image))) == NULL)
    {
      my_puterror("[*] Raytracer: Could not alloc.\n");
      return (NULL);
    }
  if (path == NULL)
    if ((image->ptr = mlx_new_image(mlx_ptr, x, y)) == NULL)
      {
	my_puterror("[*] Raytracer: Could not create image.\n");
	return (NULL);
      }
  if (path != NULL)
    if ((image->ptr = mlx_xpm_file_to_image(mlx_ptr, path, &x, &y)) == NULL)
      {
	my_puterror("Raytracer: Error: Could not create a template.\n");
	return (NULL);
      }
  image->data = mlx_get_data_addr(image->ptr, &image->bpp,
				  &image->sizeline, &image->endian);
  image->size[WIDTH] = x;
  image->size[HEIGHT] = y;
  return (image);
}
