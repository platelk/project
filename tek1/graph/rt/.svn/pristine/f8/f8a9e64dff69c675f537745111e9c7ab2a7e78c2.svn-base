/*
** import_jpg.c for import_jpg in /home/jordan/Projets/Epitech/rt/import
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Mon May 28 19:18:32 2012 jordan vanwalleghem
** Last update Sun Jun  3 11:44:18 2012 alexis leprovost
*/

#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <mlx.h>
#include <unistd.h>

#include "./jpeglib.h"
#include "image.h"
#include "my.h"

int	open_jpg(char *file_name, FILE **file,
		 struct jpeg_decompress_struct *cinfo)
{
  if (access(file_name, F_OK) == -1)
    return (-1);
  if ((*file = fopen(file_name, "rb")) == NULL)
    {
      my_putstr("Fail during opening file '");
      my_putstr(file_name);
      my_putstr("'\n");
      return (-1);
    }
  jpeg_create_decompress(cinfo);
  jpeg_stdio_src(cinfo, *file);
  jpeg_read_header(cinfo, TRUE);
  return (0);
}

void	fill_data(struct jpeg_decompress_struct *cinfo,
		  t_image *mlx_img_struct, unsigned char *image)
{
  unsigned int x;
  unsigned int y;
  int i;

  x = 0;
  i = 0;
  while (x < cinfo->image_width)
    {
      y = 0;
      while (y < cinfo->image_height)
	{
	  (mlx_img_struct->data)[i + 2] =
	    image[x * cinfo->image_height * 3 + y * cinfo->num_components];
	  (mlx_img_struct->data)[i + 1] =
	    image[x * cinfo->image_height * 3 + y * cinfo->num_components + 1];
	  (mlx_img_struct->data)[i + 0] =
	    image[x * cinfo->image_height * 3 + y * cinfo->num_components + 2];
	  i += 4;
	  y++;
	}
      x++;
    }
}

void	fill_mlx_struct(unsigned char *image,
			struct jpeg_decompress_struct *cinfo,
			t_image *mlx_img_struct, void *mlx_ptr)
{
  mlx_img_struct->bpp = 10;
  mlx_img_struct->ptr = mlx_new_image(mlx_ptr, cinfo->image_width,
				      cinfo->image_height);
  mlx_img_struct->data = mlx_get_data_addr				\
    (mlx_img_struct->ptr, &mlx_img_struct->bpp, &mlx_img_struct->sizeline,
     &mlx_img_struct->endian);
  fill_data(cinfo, mlx_img_struct, image);
  mlx_img_struct->size[0] = cinfo->image_width;
  mlx_img_struct->size[1] = cinfo->image_height;
}

unsigned char	*load_jpg_file(struct jpeg_decompress_struct *cinfo)
{
  unsigned char *ret;
  unsigned char *line;

  jpeg_start_decompress(cinfo);
  if ((ret = malloc(cinfo->image_width * cinfo->image_height	\
		    * sizeof(unsigned int))) == NULL)
    return (NULL);
  line = ret;
  while (cinfo->output_scanline < cinfo->output_height)
    {
      line = ret + 3 * cinfo->image_width * cinfo->output_scanline;
      jpeg_read_scanlines(cinfo, &line, 1);
    }
  jpeg_finish_decompress(cinfo);
  jpeg_destroy_decompress(cinfo);
  return (ret);
}

int	import_jpg(char *file_name, t_image *mlx_img_struct, void *mlx_ptr)
{
  unsigned char *image;
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  FILE *file;

  cinfo.err = jpeg_std_error(&jerr);
  if (open_jpg(file_name, &file, &cinfo) == -1)
    return (-1);
  image = load_jpg_file(&cinfo);
  fill_mlx_struct(image, &cinfo, mlx_img_struct, mlx_ptr);
  fclose(file);
  free(image);
  return (0);
}
