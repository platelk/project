/*
** main.c for main in /home/platel_k/projet/get_next_line
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov 18 10:35:05 2011 kevin platel
** Last update Fri Nov 25 14:45:18 2011 kevin platel
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
  int	fd;
  char	*str;
  if (argc < 2)
    return (0);
  fd = open(argv[1], O_RDONLY);
  while ((str = get_next_line(fd)))
    {
      my_putstr(str);
      my_putchar('\n');
      free(str);
    }
  return (0);
}
