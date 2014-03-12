/*
** fill_scene.c for fill_scene.c in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 22:39:19 2012 harold ozouf
** Last update Mon Mar  5 22:26:27 2012 harold ozouf
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	"node.h"
#include	"aff.h"
#include	"add_lum.h"
#include	"finding_elm.h"
#include	"fill_objects.h"
#include	"xfnt.h"
#include	"cores.h"
#include	"struct.h"
#include	"convert.h"
#include	"fill_struct_scene.h"
#include	"fill_scene.h"

void	fill_scene(t_scene **sc, t_node *root)
{
  fill_camera(sc, root);
  fill_lights(sc, root);
  fill_objects(sc, root);
}

void	fill_camera(t_scene **sc, t_node *root)
{
  t_node	*tmp;

  tmp = NULL;
  (*sc)->eyes = xmalloc(sizeof(*((*sc)->eyes)));
  (*sc)->rotation = xmalloc(sizeof(*((*sc)->rotation)));
  tmp = get_node("scene/camera/position/", root);
  fill_pos(&((*sc)->eyes), tmp);
  tmp = get_node("scene/camera/rotation/", root);
  fill_pos(&((*sc)->rotation), tmp);
  tmp = get_node("scene/camera/", root);
  (*sc)->fov = to_int(get_value(get_node("fov", tmp)));
  (*sc)->anti = to_int(get_value(get_node("antialiasing", tmp)));
  my_putstr("Fill camera: \t\tOK");
}

void	fill_lights(t_scene **sc, t_node *root)
{
  t_node	*tmp;
  t_pos		*pos;
  t_color	*color;

  (*sc)->lum = xmalloc(sizeof(*((*sc)->lum)));
  (*sc)->lum = NULL;
  pos = xmalloc(sizeof(*pos));
  color = xmalloc(sizeof(*color));
  tmp = get_node("scene/lights/", root);
  while (tmp->elm != NULL)
    {
      fill_pos(&pos, get_node("light/position/", tmp));
      fill_color(&color, get_node("light/color/", tmp));
      new_lum(&((*sc)->lum), pos, color);
      tmp->elm = tmp->elm->next;
    }
  my_putstr("Fill lights: \t\tOK");
  free(pos);
  free(color);
}

void	fill_objects(t_scene **sc, t_node *root)
{
  add_shape	*sh;
  t_node	*tmp;
  char		**cores;
  int		i;

  i = -1;
  sh = fill_shape();
  cores = fill_cores_shape();
  (*sc)->obj = xmalloc(sizeof(*((*sc)->obj)));
  tmp = get_node("scene/objects/", root);
  (*sc)->obj = NULL;
  while (tmp->elm != NULL)
    {
      add_obj(&((*sc)->obj), tmp, cores, sh);
      tmp->elm = tmp->elm->next;
    }
  free(sh);
  while (cores[++i])
    free(cores[i]);
  free(cores);
}

