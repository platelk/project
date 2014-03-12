/*
** read_file.c for read_file in /home/platel_k//projet/piscine/Jour_13/cat
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Oct 26 10:52:25 2011 kevin platel
** Last update Wed Oct 24 17:00:41 2012 kevin platel
*/

#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int	read_file(int fd, char *name)
{
  char	buffer[3];
  int	i;
  int	ret;

  ret = 1;
  i = 0;
  while (ret > 0)
    {
      ret = read(fd, buffer, 2);
      if (ret == -1)
	{
	  error(name);
	  return (1);
	}
      if (ret == 0 && fd == 0)
	  return (0);
      i = i + 1;
      buffer[ret] = '\0';
      my_putstr(buffer);
    }
  return (0);
}
