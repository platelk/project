/*
** export_jpg.c for export_jpg in /home/jordan/Projets/Epitech/rt/export
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Tue May 29 17:52:03 2012 jordan vanwalleghem
** Last update Sun Jun  3 08:42:55 2012 ronan guiho
*/

#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "jpeglib.h"
#include "image.h"
#include "export.h"
#include "my.h"

int	open_output_file(char *output_name, FILE **outfile,
			 struct jpeg_compress_struct *cinfo)
{
  if ((*outfile = fopen(output_name, "wb")) == NULL)
    {
      my_printf("can't open %s\n", output_name);
      return (-1);
    }
  jpeg_create_compress(cinfo);
  jpeg_stdio_dest(cinfo, *outfile);
  cinfo->input_components = 3;
  cinfo->in_color_space = JCS_RGB;
  return (0);
}

void	create_jpg_file(char *output_name,
			t_image *mlx_image_struct, unsigned char *mlx_buffer)
{
  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;
  FILE *outfile;
  JSAMPROW row_pointer[1];
  int row_stride;

  cinfo.err = jpeg_std_error(&jerr);
  open_output_file(output_name, &outfile, &cinfo);
  cinfo.image_width = mlx_image_struct->size[0];
  cinfo.image_height = mlx_image_struct->size[1];
  jpeg_set_defaults(&cinfo);
  jpeg_start_compress(&cinfo, TRUE);
  row_stride = cinfo.image_width * 3;
  while (cinfo.next_scanline < cinfo.image_height)
    {
      row_pointer[0] = &mlx_buffer[cinfo.next_scanline * row_stride];
      jpeg_write_scanlines(&cinfo, row_pointer, 1);
    }
  jpeg_finish_compress(&cinfo);
  fclose(outfile);
  jpeg_destroy_compress(&cinfo);
  free(mlx_buffer);
}

unsigned char	*convert_mlx_img(t_image *mlx_image_struct)
{
  unsigned char *ret;
  int img_pos;
  int ret_pos;
  int total_img_size;

  total_img_size = mlx_image_struct->size[0] * mlx_image_struct->size[1] * 3;
  img_pos = 0;
  ret_pos = 0;
  ret = malloc(total_img_size * sizeof(unsigned char));
  while (ret_pos < total_img_size)
    {
      ret[ret_pos] = mlx_image_struct->data[img_pos + 2];
      ret[ret_pos + 1] = mlx_image_struct->data[img_pos + 1];
      ret[ret_pos + 2] = mlx_image_struct->data[img_pos];
      ret_pos += 3;
      img_pos += 4;
    }
  return (ret);
}

void	export_jpg(t_global *global, char *dest)
{
  unsigned char *converted_mlx_img;
  t_image *img;

  img = export_image(global, -1, -1, -1);
  converted_mlx_img = convert_mlx_img(img);
  create_jpg_file(dest, img, converted_mlx_img);
  my_putstr("\n[*] Raytracer: Scene exported to : ");
  my_putstr(dest);
}
