/*
** line.c for line in /home/platel_k/projet/minilibX/lib_libx
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov  9 13:43:04 2011 kevin platel
** Last update Wed Nov  9 14:18:33 2011 kevin platel
*/

#define WIN (point->win_ptr)
#define MLX	(point->mlx_ptr)
#define Y1	point->y
#define Y2	point2->y
#define X1	point->x
#define X2	point2->x

void	line(t_point *point, t_point *point2)
{
  int	sens;
  int	x;

  x = X1;
  sens = 1;
  if (point->y > point2->y)
    sens = -1;
  while (x != X2)
    {
      mlx_pixel_put(MLX, WIN, X1, Y1+((Y2-Y1)*(x-X1))/(X2-X1), point->color);
      x = x + sens;
    }
}
