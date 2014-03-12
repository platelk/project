/*
** image.h for image in /home/guiho_r//TP/TP_igraph/tp2
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Nov 17 09:18:24 2011 ronan guiho
** Last update Mon May  7 00:27:40 2012 ronan guiho
*/

#ifndef		__MY_IMAGE_H__
#define		__MY_IMAGE_H__

typedef struct my_config
{
  char	*name;
  int	width;
  int	height;
  int	color1;
  int	color2;
  int	color3;
} t_config;

typedef struct my_window
{
  int	width_win;
  int	height_win;
  int	angle;
  int	coef;
  int	alt;
  int	flag;
  int	**map;
  void	*ptr_ini;
  void	*ptr_win;
  int	*size_file;
  int	count_col_z;
} t_window;

typedef struct my_struct_image
{
  void	*ptr_ini;
  void	*img;
  char	*data;
  int	bpp;
  int   sizeline;
  int	endian;
  int	height;
  int	width;
} t_image;

typedef		struct my_expose
{
  t_image	*t_img;
  t_window	*t_wind;
  int		**map;
  int		x;
  int		y;
} t_expose;

int		mlx_ppti(t_image *t_img, int x, int y, int color);
t_image		*initialization_img(void *ptr_ini, int height, int width);


#endif
