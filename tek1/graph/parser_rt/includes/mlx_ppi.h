/*
** mlx_ppi.h for mlx_ppi in /home/ozouf_h//projet/wolf
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Jan  6 14:39:42 2012 harold ozouf
** Last update Sun Mar 11 14:27:07 2012 harold ozouf
*/

#ifndef		MLX_PPI_H__
# define	MLX_PPI_H__
# include	"mlx.h"
# include	"struct.h"

t_color set_color(double r, double g, double b);
int     put_px_img(t_img *i, t_px *px, void *mlx_ptr);

#endif
