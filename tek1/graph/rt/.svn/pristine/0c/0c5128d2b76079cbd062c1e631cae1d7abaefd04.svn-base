/*
** obj_create_scene.c for obj in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:28:33 2012 kevin platel
** Last update Sun Jun  3 16:28:34 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"global.h"
#include	"scene.h"
#include	"object.h"
#include	"xml_tree.h"
#include	"xml_chr.h"
#include	"obj_create.h"
#include	"obj_print.h"
#include	"parse_obj.h"
#include	"my.h"
#include	"stereoscopique.h"
#include	"init.h"

t_stereoscopique	*obj_create_3D(int x, int y, void *mlx_ptr, t_xtree *tree)
{
  t_stereoscopique	*new;
  t_xtree		*tmp;

  if ((tmp = xml_find_in_tree(tree, "window", 0)) == NULL)
    return (NULL);
  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->image = init_image(mlx_ptr, NULL, x, y);
  new->size = my_getnbr(xml_find_attr(tmp->attr, "STEREOSCOPIE"));
  return (new);
}

t_scene	 *obj_add_scene(t_xtree *tree, t_scene *scene, void *mlx_ptr)
{
  t_scene	*new;
  t_object	*tmp;

  new = malloc(sizeof(*new));
  if (new == NULL)
    return (NULL);
  tmp = obj_create_list_object(tree, STRING_NEG, NULL, mlx_ptr);
  new->light = obj_create_list_light(tree);
  new->filter = my_getnbr_base(xml_find_attr(tree->attr, "FILTER"), \
			       BASE_STRING);
  new->wizzard = my_getdouble(xml_find_attr(tree->attr, "WIZZARD"));
  new->camera = obj_create_list_cam(tree);
  new->object = obj_create_list_object(tree, STRING_NORM, tmp, mlx_ptr);
  parse_3ds(&new->object);
  new->antialiasing = my_getdouble(xml_find_attr(tree->attr, STRING_AA));
  new->image = NULL;
  new->next = NULL;
  new->prev = scene;
  if (scene)
    scene->next = new;
  return (new);
}

t_scene	*obj_create_scene(t_xtree *tree, void *mlx_ptr)
{
  t_scene	*scene;
  t_scene	*tmp;

  tree = xml_find_in_tree(tree, "window/scene", 0);
  if (tree == NULL)
    return (NULL);
  scene = obj_add_scene(tree, NULL, mlx_ptr);
  tmp = scene;
  tree = tree->next;
  while (tree)
    {
      tmp = obj_add_scene(tree, tmp, mlx_ptr);
      tree = tree->next;
    }
  return (scene);
}
