/*
** export_bmp.c for Export BMP in /home/guiho_r/tek1/rtv1/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Mar 31 15:58:49 2012 ronan guiho
** Last update Sat Jun  2 09:45:14 2012 jordan vanwalleghem
*/

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "my.h"
#include "image.h"
#include "export.h"
#include "header.h"

int		create_filebmp(char *name)
{
  int		fd;

  if ((fd = open(name, O_CREAT | O_WRONLY | O_TRUNC,
		 S_IRUSR | S_IWUSR)) == -1)
    {
      my_putstr("Raytracer: Export_BMP: Can't create file <");
      my_putstr(name);
      my_putstr(".bmp>.\n");
      return (-1);
    }
  return (fd);
}

int		write_headerbmp(t_image *img, int fd)
{
  t_headerbmp	header;

  header.img_size = (img->size[WIDTH] * img->size[HEIGHT] * 32) * 8 + 36;
  header.reserved1 = 0;
  header.addr_begin = 0x36;
  header.size_part = 0x28;
  header.width_image = img->size[WIDTH];
  header.height_image = img->size[HEIGHT];
  header.plan_bpp = 0x00200001;
  header.compression = 0;
  header.size_data = (img->size[WIDTH] * img->size[HEIGHT] * 32) * 8;
  header.reso_horizon = 0;
  header.reso_vertical = 0;
  header.nb_color_use = 0;
  header.nb_color_imp = 0;
  if (write(fd, "BM", 2) != 2)
    return (EXIT_FAILURE);
  if (write(fd, &header, sizeof(t_headerbmp)) != sizeof(t_headerbmp))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		write_pixelbmp(int fd, int R, int G, int B)
{
  t_colorbmp	colorbmp;

  colorbmp.R = R;
  colorbmp.G = G;
  colorbmp.B = B;
  colorbmp.A = 0;
  if (write(fd, &colorbmp, sizeof(t_colorbmp)) != sizeof(t_colorbmp))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		export_bmp(t_global *global, char *name, int i)
{
  int		fd;
  int		x;
  int		y;
  t_image	*img;

  if ((img = export_image(global, -1, -1, -1)) == NULL)
    return (EXIT_FAILURE);
  if ((fd = create_filebmp(name)) == -1)
    return (EXIT_FAILURE);
  write_headerbmp(img, fd);
  y = img->size[HEIGHT];
  while (y > 0)
    {
      x = 0;
      while (x < img->size[WIDTH])
	{
	  i = (y * img->sizeline) + (x * (img->bpp / 8));
	  write_pixelbmp(fd, (int)img->data[i + 2], (int)img->data[i + 1],
			 (int)img->data[i]);
	  x++;
	}
      y--;
    }
  return (EXIT_SUCCESS);
}
