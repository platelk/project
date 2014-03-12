/*
** get_next_line.c for get_next_line in /home/platel_k/projet/get_next_line
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Nov 14 13:57:53 2011 kevin platel
** Last update Fri Dec  9 09:27:49 2011 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE];
  char		*str;
  static int	i;
  static int	j;

  if ((str = malloc(BUFFER_SIZE + 1 * sizeof(char))) == 0 || BUFFER_SIZE == 0)
    return (NULL);
  i = 0;
  while (j < READ_SIZE && buffer[++j] == '\n' && buffer[j] != '\0');
  while (buffer[j] != '\0' && buffer[j] != '\n' && i != BUFFER_SIZE)
    str[i++] = buffer[j++];
  while ((i != BUFFER_SIZE && buffer[j] != '\n') || (j== 0 && i == 0))
    {
      if ((j = read(fd, buffer, READ_SIZE)) == -1 || (j == 0 && i == 0))
	return (NULL);
      buffer[j] = '\0';
      str[i] = '\0';
      if (j == 0 && i != 0)
	return (str);
      j = 0;
      while (buffer[j] != '\0' && buffer[j] != '\n' && i != BUFFER_SIZE)
	str[i++] = buffer[j++];
    }
  str[i] = '\0';
  return (str);
}
