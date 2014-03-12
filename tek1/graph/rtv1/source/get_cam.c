/*
** get_cam.c for get_cam in /home/vink/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  8 14:26:00 2012 kevin platel
** Last update Fri Feb 17 15:23:25 2012 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "scene.h"
#include "camera.h"
#include "error_file.h"
#include "rt.h"

t_cam   *new_cam(char *name, t_cam *cam, void *father)
{
  t_cam	*new;
  t_attr  *attr;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (new);
  while (cam != NULL && cam->next != NULL)
    cam = cam->next;
  attr = get_attr(name, new);
  if (attr == NULL)
    return (NULL);
  if ((new = get_pos(new, attr)) == NULL)
    return (NULL);
  if (search_attr(new->attr, FOV_STR) != NULL)
    new->fov = my_getnbr(search_attr(new->attr, FOV_STR));
  new->father = father;
  new->prev = cam;
  new->next = NULL;
  if (cam != NULL)
    cam->next = new;
  return (new);
}

char	*get_cam(int fd, t_cam **cam, void *father)
{
  int	error;
  char	*buffer;

  (*cam) = NULL;
  error = 0;
  while (((buffer) = get_next_line(fd)) != NULL &&
	 (error = check_balise(buffer, "camera")) != ERROR_NO_DEF_NAME)
    {
      if ((error = check_balise((buffer), "camera")) < 0)
	{
	  print_balise_error(error);
	  return (NULL);
	}
      (*cam) = new_cam(buffer, (*cam), father);
      if ((*cam) == NULL)
	return (NULL);
      if (buffer != NULL)
	free(buffer);
    }
  if ((buffer) == NULL)
    {
      my_printf("Error, no end-balise to <scene ...>\n");
      return (NULL);
    }
  return (buffer);
}
