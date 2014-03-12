/*
** mlx.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 17:36:18 2012 alexis leprovost
** Last update Sun Jun  3 06:17:22 2012 kevin platel
*/

#ifndef __MLX_H__
#define __MLX_H__

#include	"global.h"
#include	"color.h"
#include	"image.h"

void    *mlx_init();
void    *mlx_new_window(void *, int, int, char *);
void    *mlx_new_image(void *, int, int);
char    *mlx_get_data_addr(void *, int *, int *, int *);
int     mlx_put_image_to_window(void *, void *, void *, int, int);
int     mlx_mouse_hook (void *, int (*)(), void *);
int     mlx_key_hook (void *, int (*)(), void *);
int     mlx_expose_hook (void *, int (*)(), void *);
int     mlx_loop (void *);
void    *mlx_xpm_to_image(void *, char **, int *, int *);
void    *mlx_xpm_file_to_image(void *, char *, int *, int *);
int     mlx_hook(void *, int, int, int (*)(), void *);
int	mlx_ppti(t_image *, t_color *, int, int);

#endif
