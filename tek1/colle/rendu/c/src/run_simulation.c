/*
** run_simulation.c for colle in /home/vink/projet/colle/rendu/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 26 23:38:28 2012 kevin platel
** Last update Thu Apr 26 23:59:16 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"get.h"
#include	"check.h"
#include	"print.h"
#include	"sand_pile.h"
#include	"put.h"

int	my_str_is_num(char *str)
{
  while (*str)
    {
      if (IS_NUM(*str) == -1)
	return (1);
      str++;
    }
  return (0);
}

int	run_simulation(char **map, char *sand)
{
  char	buffer[BUFFER_SIZE + 1];
  int	it;
  int	len;

  it = 0;
  system("clear");
  print_sand(map);
  while (it >= 0)
    {
      len = read(0, buffer, BUFFER_SIZE);
      buffer[len - 1] = 0;
      if (my_str_is_num(buffer) > 0)
	{
	  my_puterr(buffer);
	  my_puterr(" is not a num\n");
	  return (1);
	}
      it = getnbr(buffer);
      sand_pile(map, sand, it);
    }
  return (0);
}
