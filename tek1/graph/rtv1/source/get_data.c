/*
** get_data.c for get_data in /home/platel_k/projet/graph/rtv1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Feb  1 13:25:07 2012 kevin platel
** Last update Thu Feb  9 13:10:45 2012 kevin platel
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "my.h"
#include "scene.h"
#include "rt.h"

t_scene	*get_data(char *path)
{
  int	fd;
  t_scene	*scene;
  char		*buffer;

  if ((fd = open(path, O_RDONLY)) == -1)
    {
      my_printf("Error, can't open file -> [%s] ", path);
      return (NULL);
    }
  buffer = get_next_line(fd);
  while (buffer != NULL && buffer[0] != OPEN_CHAR)
    buffer = get_next_line(fd);
  if (buffer == NULL)
    return (NULL);
  scene = get_scene(fd, buffer);
  return (scene);
}
