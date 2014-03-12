/*
** main.c for cat main in /home/platel_k/projet/piscine/Jour_13/cat
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Oct 26 10:32:08 2011 kevin platel
** Last update Fri Nov  2 18:33:46 2012 kevin platel
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#include "my.h"

int	read_file(int fd, char *name);
int	error(char *name);

int	main(int argc, char **argv)
{
  int	i;
  int	fd;
  int	end;

  end = 0;
  i = 1;
  while (argc > i)
    {
      fd = open(argv[i], O_RDONLY);
      if (fd == -1 && argv[i][0] != '-')
	error(argv[i]);
      else
	{
	  if (argc == 1 || (argv[i][0] == '-'))
	      fd = 0;
	  read_file(fd, argv[i]);
	}
      if (fd != 0)
	close(fd);
      i = i + 1;
    }
  return (0);
}
