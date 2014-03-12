/*
** cores.c for cores in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Feb 17 10:57:31 2012 harold ozouf
** Last update Thu Apr 26 13:14:50 2012 kevin platel
*/

#include	<stdlib.h>
#include	"xfnt.h"
#include	"str.h"
#include	"fill_objects.h"
#include	"fill_scene.h"
#include	"cores.h"

add_shape	*fill_shape(void)
{
  add_shape	*sh;

  sh = xmalloc(sizeof(*sh) * 4);
  sh[0] = &add_sphere;
  sh[1] = &add_cylinder;
  sh[2] = &add_plan;
  sh[3] = &add_cone;
  return (sh);
}

char	**fill_cores_shape(void)
{
  char	**cores;

  cores = xmalloc(sizeof(*cores) * (4 + 1));
  cores[0] = my_strdup("sphere");
  cores[1] = my_strdup("cylinder");
  cores[2] = my_strdup("plan");
  cores[3] = my_strdup("cone");
  cores[4] = NULL;
  return (cores);
}
