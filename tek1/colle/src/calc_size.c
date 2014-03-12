/*
** calc_size.c for colle in /home/vink/projet/colle/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 26 21:32:01 2012 kevin platel
** Last update Thu Apr 26 22:54:36 2012 kevin platel
*/

int	calc_mid_width(char **map)
{
  int	i;

  i = 0;
  while (map && map[i])
    i++;
  return (i / 2);
}

int	calc_mid_height(char **map)
{
  int	i;

  i = 0;
  while (map && map[0] && map[0][i])
    i++;
  return (i / 2);
}
