/*
** get_object.c for get_object in /home/vink/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  8 21:51:16 2012 kevin platel
** Last update Sat Mar 10 16:58:37 2012 kevin platel
*/

#include <stdlib.h>
#include "rt.h"
#include "my.h"
#include "error_file.h"
#include "object.h"
#include "attribute.h"
#include "camera.h"

int	get_type(char *line)
{
  if (my_find_str(line, "sphere") > 0)
    return (SPHERE);
  if (my_find_str(line, "plan") > 0)
    return (PLAN);
  if (my_find_str(line, "cone") > 0)
    return (CONE);
  if (my_find_str(line, "cyl") > 0)
    return (CYL);
  return (0);
}

t_object    *new_object(char *name, t_object *obj, void *father)
{
  t_object	*new;
  t_attr  *attr;

  if ((new = malloc(sizeof(*new))) == NULL)
    return (new);
  attr = get_attr(name, new);
  if (attr == NULL)
    {
      my_printf("Error, [%s] have no attribute\n", name);
      return (NULL);
    }
  if ((new = get_pos_obj(new, attr)) == NULL)
    return (NULL);
  new->type = get_type(name);
  if ((new->type == SPHERE || new->type == CYL || new->type == CONE) &&
      search_attr(new->attr, "r") != NULL)
    new->r = my_getnbr(search_attr(new->attr, "r"));
  else
    new->r = 300;
  new->father = father;
  new->prev = obj;
  new->next = NULL;
  if (obj != NULL)
    obj->next = new;
  return (new);
}

char	*get_object(int fd, t_object **obj, void *father)
{
  int	error;
  char	*buffer;

  error = 0;
  (*obj) = NULL;
  while (((buffer) = get_next_line(fd)) != NULL &&
	 (my_find_str(buffer, "/obj")) < 0)
    {
      if ((error = check_balise((buffer), "/obj")) < 0
	  && error != ERROR_NO_DEF_NAME)
	{
	  my_printf("%s", buffer);
	  print_balise_error(error);
	  return (NULL);
	}
      (*obj) = new_object(buffer, (*obj), father);
      if ((*obj) == NULL)
	  return (NULL);
      if (buffer != NULL)
	free(buffer);
    }
  while ((*obj) && (*obj)->prev != NULL)
    (*obj) = (*obj)->prev;
  return (buffer);
}
