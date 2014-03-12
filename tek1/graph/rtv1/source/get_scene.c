/*
** get_scene.c for get_scene in /home/vink/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  8 14:24:16 2012 kevin platel
** Last update Sun Feb 19 15:31:52 2012 kevin platel
*/

#include <stdlib.h>

#include "my.h"
#include "error_file.h"
#include "scene.h"
#include "rt.h"
#include "light.h"

t_scene	*get_scene(int fd, char *buffer)
{
  t_scene	*scene;
  int	error;

  if ((error = check_balise(buffer, "scene")) < 0)
    return (NULL);
  scene = malloc(sizeof(*scene));
  scene->attr = get_attr(buffer, scene);
  buffer = get_cam(fd, &(scene->cam), scene);
  if (scene->cam == NULL)
    return (NULL);
  if ((error = check_balise(buffer, "object")) == ERROR_NO_DEF_NAME
      && check_balise(buffer, "light") == ERROR_NO_DEF_NAME)
    return (NULL);
  buffer = get_object(fd, &(scene->obj), scene);
  if (scene->obj == NULL)
    return (NULL);
  buffer = get_next_line(fd);
  if ((error = check_balise(buffer, "light")) == ERROR_NO_DEF_NAME)
    return (NULL);
  buffer = get_light(fd, &(scene->light), scene);
  if (scene->light == NULL)
    return (NULL);
  return (scene);
}
