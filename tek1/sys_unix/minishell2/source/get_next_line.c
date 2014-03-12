/*
** get_next_line.c for get_next_line in /home/platel_k/projet/get_next_line
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Nov 14 13:57:53 2011 kevin platel
** Last update Sat Dec 31 01:27:15 2011 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"
#include "get_next_line.h"

char		*get_next_line(const int fd, t_env *env, t_pwd *my_pwd)
{
  char	buffer[READ_SIZE];
  char		*str;
  int	i;
  int	j;

  i = 0;
  j = 0;
  if ((str = malloc(BUFFER_SIZE * sizeof(char))) == NULL || BUFFER_SIZE == 0)
    return (NULL);
  while ((i != BUFFER_SIZE && buffer[j] != '\n') || (j== 0 && i == 0))
    {
      if ((j = read(fd, buffer, READ_SIZE)) == -1 || (j == 0 && i == 0))
	quit(env, my_pwd);
      buffer[j + 1] = '\0';
      if (buffer[0] == '\n')
	return (NULL);
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
