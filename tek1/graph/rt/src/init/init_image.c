/*
** init_image.c for raytracer in /home/leprov_a//depot/rt/src
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Tue May  1 20:47:29 2012 alexis leprovost
** Last update Sun Jun  3 18:55:43 2012 ronan guiho
*/

#include        <stdio.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>

#include	"image.h"
#include	"mlx.h"
#include	"my.h"
#include	"determ_img_type.h"
#include	"import_jpg.h"
#include	"import_bmp.h"

char	*my_puterror_n_ret_null(char *str)
{
  int len;

  if (str != NULL)
    {
      len = write(2, str, strlen(str));
      if (len != my_strlen(str))
	exit(-1);
    }
  return (NULL);
}

t_image *empty_image(t_image *image, int x, int y, void *mlx_ptr)
{
  image->ptr = mlx_new_image(mlx_ptr, x, y);
  image->data = mlx_get_data_addr(image->ptr, &image->bpp,
				  &image->sizeline, &image->endian);
  image->size[0] = x;
  image->size[1] = y;
  image->type = B_NONE;
  image->cut_texture = NULL;
  image->type_texture = 0;
  image->relief = 0.0F;
  image->freq = 1.0F;
  return (image);
}

int	create_default_img(t_image *image, void *mlx_ptr)
{
  empty_image(image, 100, 100, mlx_ptr);
  return (-1);
}

t_image	*init_image(void *mlx_ptr, char *path, int x, int y)
{
  t_image	*image;
  int img_type;

  if (mlx_ptr == NULL)
      return (NULL);
  if ((image = malloc(sizeof(*image))) == NULL)
    return (NULL);
  if (path == NULL && x == 0 && y == 0)
    return (NULL);
  if (path == NULL)
    return (empty_image(image, x, y, mlx_ptr));
  img_type = determ_img_type(path);
  if (img_type == JPG && import_jpg(path, image, mlx_ptr) == -1)
    return (NULL);
  if (img_type == XPM &&
      ((image->ptr = mlx_xpm_file_to_image				\
	(mlx_ptr, path, &image->size[WIDTH], &image->size[HEIGHT])) == NULL ||
       (image->data = mlx_get_data_addr					\
	(image->ptr, &image->bpp, &image->sizeline, &image->endian)) != NULL))
    img_type = IMG_ERROR;
  if (img_type == IMG_ERROR && create_default_img(image, mlx_ptr) == -1)
    my_puterror_n_ret_null("[*] Raytracer: Could not create image.\n");
  return (img_type == BMP ? NULL :
	  img_type == IMG_ERROR ? NULL : image);
}
