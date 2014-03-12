/*
** my_sqrt.c for my_sqrt in /home/guiho_r/tmp
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  9 18:21:14 2012 ronan guiho
** Last update Wed May  9 20:52:23 2012 ronan guiho
*/

double		my_sqrt(double value)
{
  int		i;
  double	r;

  i = -1;
  r = (value > 1) ? 2.0 * value : value / 2.0;
  while (++i < 5)
    r = (r + (value / r)) / 2.0;
  return (r);
}
