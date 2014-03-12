/*
** get_data.c for get_data in /home/platel_k/projet/bsq/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Dec  8 11:10:12 2011 kevin platel
** Last update Sun Dec 11 12:32:57 2011 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "get_next_line.h"
#include "bsq.h"

char	**get_data(char *link)
{
  int   fd;
  char  *line;
  char  **data;
  int	size;
  int	j;

  fd = open(link, O_RDONLY);
  fd == -1 ? exit(0) : 42;
  if ((line  = get_next_line(fd)) == NULL)
    exit (0);
  size =  my_getnbr(line);
  size <= 0 ? exit(0) : 42;
  data = malloc((size + 1) * sizeof(*data));
  if (data == NULL)
    return (0);
  j = 0;
  while (j < size && (line = get_next_line(fd)) != NULL)
    {
      data[j] = my_strdup(line);
      free(line);
      j++;
    }
  data[j] = NULL;
  return (data);
}
