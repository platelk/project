/*
** sand_pile.c for sand_pile in /home/vink/projet/colle/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 26 21:17:37 2012 kevin platel
** Last update Fri Apr 27 00:10:16 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"print.h"
#include	"sand_pile.h"
#include	"calc_size.h"

int	get_value_of_pile(char c, char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (c == str[i])
	return (i);
      i++;
    }
  return (-1);
}

int	get_char_of_pile(char c, char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    {
      if (c == str[i])
	return (str[i]);
      i++;
    }
  return (-1);
}

int	check_is_stable(char **map, int i, int j, char *str)
{
  if (get_value_of_pile(map[i][j], str) + 1 > 3)
    {
      map[i][j] = -1;
      analyse_sand_pile(map, str, i, j);
      return (1);
    }
  else
    map[i][j] = str[get_value_of_pile(map[i][j], str) + 1];
  return (0);
}

char	analyse_sand_pile(char **map, char *str, int i, int j)
{
  if (map && map[i] && map[i][j])
    {
      if (get_value_of_pile(map[i][j], str) < 0)
	{
	  map[i][j] = str[0];
	  if (map[i + 1] && map[i + 1][j])
	    check_is_stable(map, i + 1, j, str);
	  if (i > 0 && map[i - 1] && map[i - 1][j])
	    check_is_stable(map, i - 1, j, str);
	  if (map[i][j + 1])
	    check_is_stable(map, i, j + 1, str);
	  if (j > 0 && map[i][j - 1])
	    check_is_stable(map, i, j - 1, str);
	}
    }
  if (map && map[i] && map[i][j] == '\0')
    analyse_sand_pile(map, str, i + 1, 0);
  else if (map && map[i])
    analyse_sand_pile(map, str, i, j + 1);
  return (0);
}

int	sand_pile(char **map, char *sand, int it)
{
  int	width;
  int	height;

  width = calc_mid_width(map);
  height = calc_mid_height(map);
  while (it > 0)
    {
      if ((get_value_of_pile(map[width][height], sand) + 1) > 3)
	map[width][height] = -1;
      else
	map[width][height] =
	  (sand[get_value_of_pile(map[width][height], sand) + 1]);
      analyse_sand_pile(map, sand, 0, 0);
      system("clear");
      print_sand(map);
      sleep(1);
      it--;
    }
  return (0);
}
