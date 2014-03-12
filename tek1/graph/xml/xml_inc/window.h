/*
** window.h for raytracer in /home/leprov_a//depot/rt/inc
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Tue May  1 15:49:13 2012 alexis leprovost
** Last update Mon May  7 15:48:58 2012 kevin platel
*/

#ifndef __WINDOW_H__
#define __WINDOW_H__

#include	"image.h"
#include	"xml_attr.h"

#define	NUM_WIN_X	(500)
#define	NUM_WIN_Y	(500)

#define	STRING_WINDOW	"window"
#define STRING_Y_WIN	"y"
#define STRING_X_WIN	"x"
#define STRING_WIN_NAME "name"

typedef struct s_window
{
  t_image	*image;
  void	*mlx_ptr;
  void	*win_ptr;
  char	*name_win;
  int	y_win;
  int	x_win;
  t_attr	*attr;
} t_window;

#endif
