/*
** object.c for object in /home/ozouf_h//projet/rt_v1/srcs/raytrace
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sun Mar 11 14:30:48 2012 harold ozouf
** Last update Wed Apr 25 14:21:00 2012 kevin platel
*/

#include	<stdlib.h>
#include	"fill_struct_scene.h"
#include	"aff.h"
#include	"finding_elm.h"
#include	"xfnt.h"
#include	"convert.h"
#include	"struct.h"
#include	"sphere.h"
#include	"cone.h"
#include	"plan.h"
#include	"cylinder.h"
#include	"object.h"

void	add_sphere(t_shape **s, t_shape *p, t_node *nd)
{
  double	r;

  p->arg = xmalloc(sizeof(t_sphere *));
  r = to_double(get_value(get_node("radius", nd)));
  ((t_sphere *)p->arg)->radius = r;
  p->next = *s;
  *s = p;
  my_putstr("ajout d'une sphere\tOK");
}

void	add_cone(t_shape **s, t_shape *p, t_node *nd)
{
  double	a;

  p->arg = xmalloc(sizeof(t_cone *));
  a = to_double(get_value(get_node("angle", nd)));
  ((t_cone *)p->arg)->angle = a;
  p->next = *s;
  *s = p;
  my_putstr("ajout d'un cone\tOK");
}

void	add_plan(t_shape **s, t_shape *p, t_node *nd)
{
  if (nd != NULL)
    {
      p->arg = xmalloc(sizeof(t_plan *));
      ((t_plan *)p->arg)->max = xmalloc(sizeof(*(((t_plan *)p->arg)->max)));
      ((t_plan *)p->arg)->min = xmalloc(sizeof(*(((t_plan *)p->arg)->min)));
      fill_pos(&(((t_plan *)p->arg)->max), get_node("max", nd));
      fill_pos(&(((t_plan *)p->arg)->min), get_node("min", nd));
      p->next = *s;
      *s = p;
      my_putstr("ajout d'un plan\t\tOK");
    }
}

void	add_cylinder(t_shape **s, t_shape *p, t_node *nd)
{
  double	r;

  p->arg = xmalloc(sizeof(t_cylinder *));
  r = to_double(get_value(get_node("radius", nd)));
  ((t_cylinder *)p->arg)->radius = r;
  p->next = *s;
  *s = p;
  my_putstr("ajout d'un cylindre\tOK");
}
