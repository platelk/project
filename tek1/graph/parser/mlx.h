/*
** mlx.h for mlx.h in /home/ozouf_h//projet/rtv1/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb  1 16:02:07 2012 harold ozouf
** Last update Sun Mar 11 14:27:01 2012 harold ozouf
*/

#ifndef		MLX_H__
# define	MLX_H__

int           mlx_loop (void *);
void          *mlx_init(void);
void          *mlx_new_window(void *, int, int, char *);
void          *mlx_new_image(void *, int, int);
int           mlx_put_image_to_window(void *, void *, void *, int, int);
char          *mlx_get_data_addr(void *, int *, int *, int *);
unsigned int  mlx_get_color_value(void *, int);
int           mlx_expose_hook(void *win_ptr, int (*funct_ptr)(), void *param);
int           mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);

#endif
