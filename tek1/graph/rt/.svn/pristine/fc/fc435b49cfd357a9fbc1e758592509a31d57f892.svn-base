/*
** obj_create_list_cam.c for obj in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:27:51 2012 kevin platel
** Last update Sun Jun  3 16:27:52 2012 kevin platel
*/

#include	<stdlib.h>

#include	"global.h"
#include	"my.h"
#include	"xml_tree.h"
#include	"xml_chr.h"
#include	"camera.h"
#include	"light.h"

void		obj_bzero_cam_dim(double *tab)
{
  tab[X] = 0.0;
  tab[Y] = 0.0;
  tab[Z] = 0.0;
}

t_camera	*obj_init_cam_dimension(t_xtree *tmp, t_camera *new, t_xtree *tree)
{
  if ((tmp = xml_find_in_tree(tree, STRING_LOC, 0)) != NULL)
    {
      new->position[X] = my_getnbr(xml_find_attr(tmp->attr, STRING_X));
      new->position[Y] = my_getnbr(xml_find_attr(tmp->attr, STRING_Y));
      new->position[Z] = my_getnbr(xml_find_attr(tmp->attr, STRING_Z));
    }
  else
    obj_bzero_cam_dim(new->position);
  if ((tmp = xml_find_in_tree(tree, STRING_ROT, 0)) != NULL)
    {
      new->rotation[X] = my_getnbr(xml_find_attr(tmp->attr, STRING_X));
      new->rotation[Y] = my_getnbr(xml_find_attr(tmp->attr, STRING_Y));
      new->rotation[Z] = my_getnbr(xml_find_attr(tmp->attr, STRING_Z));
    }
  else
    obj_bzero_cam_dim(new->rotation);
  return (new);
}

t_camera	*obj_create_cam(t_xtree *tree, t_camera *cam)
{
  t_camera	*new;
  t_xtree	*tmp;

  new = malloc(sizeof(*new));
  if (!new)
    return (NULL);
  new = obj_init_cam_dimension(tree, new, tree);
  tmp = xml_find_in_tree(tree, "camera/fov", 0);
  if (!tmp)
    new->fov = 0.0;
  else
    new->fov = my_getnbr(tmp->content);
  new->next = NULL;
  new->prev = cam;
  if (cam)
    cam->next = new;
  return (new);
}

t_camera	*obj_create_list_cam(t_xtree *tree)
{
  t_camera	*cam;
  t_camera	*tmp;

  tree = xml_find_in_tree(tree, "window/scene/cameras/camera", 0);
  if (!tree)
    return (NULL);
  cam = NULL;
  tmp = cam;
  while (tree)
    {
      tmp = obj_create_cam(tree, tmp);
      if (cam == NULL)
	cam = tmp;
      tree = tree->next;
    }
  return (cam);
}
