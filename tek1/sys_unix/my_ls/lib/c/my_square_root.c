/*
** my_square_root.c for my_square_root in /home/platel_k//lib/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 10:13:32 2011 kevin platel
** Last update Sat Nov 19 18:40:06 2011 kevin platel
*/

int	my_square_root(int nbr)
{
  int	i;

  i = 0;
  while ((i * i) <= nbr)
      i = i + 1;
  if ((i * i) > nbr)
    i = i - 1;
  return (i);
}
