/*
** is_big_endian.c for is_big_endian in /home/platel_k//projet/piscine/Jour_09/ex_05
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Oct 13 15:13:31 2011 kevin platel
** Last update Thu Jan 10 08:39:54 2013 vink
*/

int	is_big_endian(void)
{
  int	i;
  char	*p_i;

  i = 252;
  p_i = &i;
  if (*p_i == -4)
    return (1);
  return (0);
}
