/*
** my_cbrt.c for my_cbrt in /home/guiho_r/tmp
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  9 19:05:13 2012 ronan guiho
** Last update Wed May  9 19:15:01 2012 ronan guiho
*/

double		my_cbrt(double value)
{
  int		i;
  int		r;

  i = -1;
  r = value;
  while (++i < 5)
    r = (1.0 / 3.0) * (2.0 * r + value / (r * r));
  return (r);
}
