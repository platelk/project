/*
** import_bmp.c for Import BMP in /home/guiho_r/tek1/rtv1/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Mar 31 23:56:26 2012 ronan guiho
** Last update Sun Jun  3 13:40:36 2012 kevin platel
*/

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "image.h"
#include "mlx.h"
#include "my.h"
#include "header.h"

t_image		*import_imagebmp(void *mlx_ptr, int x, int y)
{
  t_image	*image;

  if ((image = malloc(sizeof(*image))) == NULL)
    {
      my_puterror("[*] Raytracer: Could not alloc.\n");
      return (NULL);
    }
  if ((image->ptr = mlx_new_image(mlx_ptr, x, y)) == NULL)
    {
      my_puterror("[*] Raytracer: Could not create image.\n");
      return (NULL);
    }
  image->data = mlx_get_data_addr(image->ptr, &image->bpp,
				  &image->sizeline, &image->endian);
  image->size[WIDTH] = x;
  image->size[HEIGHT] = y;
  return (image);
}
int		import_openbmp(char *name, int *width, int *height, char *buffer)
{
  int		fd;

  if ((fd = open(name, O_RDONLY)) == -1)
    return (-1);
  if (read(fd, buffer, 18) != 18)
    return (-1);
  if (read(fd, width, 4) != 4)
    return (-1);
  if (read(fd, height, 4) != 4)
    return (-1);
  if (read(fd, buffer, 28) != 28)
    return (-1);
  return (fd);
}
