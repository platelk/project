/*
** get_light.c for get_light in /home/vink/projet/graph/rtv1
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Feb 17 11:13:40 2012 kevin platel
** Last update Sat Feb 18 18:24:47 2012 kevin platel
*/

#include <stdlib.h>
#include "rt.h"
#include "my.h"
#include "error_file.h"
#include "object.h"
#include "attribute.h"
#include "light.h"
#include "camera.h"

t_light    *new_light(char *name, t_light *obj, void *father)
{
  t_light	*new;
  t_attr  *attr;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (new);
  attr = get_attr(name, new);
  if (attr == NULL)
    {
      my_printf("Error, [%s] have no attribute\n", name);
      return (NULL);
    }
  if ((new = get_pos_light(new, attr)) == NULL)
    return (NULL);
  new->father = father;
  new->prev = obj;
  new->next = NULL;
  if (obj != NULL)
    obj->next = new;
  return (new);
}

char	*get_light(int fd, t_light **light, void *father)
{
  int	error;
  char	*buffer;

  error = 0;
  (*light) = NULL;
  while (((buffer) = get_next_line(fd)) != NULL &&
	 (my_find_str(buffer, "/light")) < 0)
    {
      if ((error = check_balise((buffer), "/light")) < 0
	  && error != ERROR_NO_DEF_NAME)
	{
	  my_printf("%s", buffer);
	  print_balise_error(error);
	  return (NULL);
	}
      (*light) = new_light(buffer, (*light), father);
      if ((*light) == NULL)
	  return (NULL);
      if (buffer != NULL)
	free(buffer);
    }
  while (light && (*light) && (*light)->prev != NULL)
    (*light) = (*light)->prev;
  return (buffer);
}
