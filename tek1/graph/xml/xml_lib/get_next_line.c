/*
** get_next_line.c for Get_Next_Line in /home/guiho_r/tek1/corewar/lib/libmy
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Mar 25 20:43:39 2012 ronan guiho
** Last update Sun May  6 17:23:39 2012 kevin platel
*/

#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

#define B	buffer

char		*get_next_line(const int fd)
{
  static char	buffer[READ_SIZE];
  char		*str;
  static int	i;
  static int	j;

  if (BUFFER_SIZE == 0 || (str = malloc(BUFFER_SIZE * sizeof(char))) == NULL)
    return (NULL);
  while (!(i = 0) && j < READ_SIZE && B[++j] == '\n' && B[j] != 0);
  while (buffer[j] != '\0' && buffer[j] != '\n' && i != BUFFER_SIZE)
    str[i++] = buffer[j++];
  while ((i != BUFFER_SIZE && buffer[j] != '\n') || (j== 0 && i == 0))
    {
      if ((j = read(fd, buffer, READ_SIZE)) == -1 || (j == 0 && i == 0))
	return (NULL);
      buffer[j + 1] = '\0';
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
