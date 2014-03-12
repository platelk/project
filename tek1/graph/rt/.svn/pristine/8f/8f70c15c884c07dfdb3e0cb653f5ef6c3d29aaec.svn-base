/*
** init_triangle.c for init_triangle.c in /home/ozouf_h//rt/src/parser_obj
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Jun  1 03:25:21 2012 harold ozouf
** Last update Sun Jun  3 17:07:17 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"object.h"
#include	"init.h"
#include	"obj_create.h"
#include	"init_triangle.h"

int	copy_tab(double *tab1, double *tab2)
{
  if (tab2 == NULL || tab2 == NULL)
    return (0);
  tab1[0] = tab2[0];
  tab1[1] = tab2[1];
  tab1[2] = tab2[2];
  return (1);
}

void	vectorize(double *r, double *u, double *v)
{
  r[0] = v[0] - u[0];
  r[1] = v[1] - u[1];
  r[2] = v[2] - u[2];
}

void	add_triangle_bis(t_object *new, t_object *parent)
{
  new->attr = parent->attr;
  new->limit = parent->limit;
  new->inter = &inter_triangle;
  new->material = parent->material;
  new->inhibitor = parent->inhibitor;
  new->type = TRIANGLE;
  new->color = parent->color;
}

void	add_triangle(t_object **o, double pt[3][3],
		     double *n, t_object *parent)
{
  t_object	*new;

  if ((new = malloc(sizeof(*new))) == NULL)
    exit(1);
  copy_tab(new->position, parent->position);
  copy_tab(new->rotation, parent->rotation);
  new->son = malloc(sizeof(t_triangle));
  copy_tab(((t_triangle *)new->son)->pt1, pt[0]);
  copy_tab(((t_triangle *)new->son)->pt2, pt[1]);
  copy_tab(((t_triangle *)new->son)->pt3, pt[2]);
  copy_tab(((t_triangle *)new->son)->n, n);
  copy_tab(new->effect, parent->effect);
  copy_tab(new->perturbation, parent->perturbation);
  new->perlin = parent->perlin;
  new->image = parent->image;
  new->texture_pos[0] = parent->texture_pos[0];
  new->texture_pos[1] = parent->texture_pos[1];
  new->image_bump = parent->image_bump;
  add_triangle_bis(new, parent);
  if (*o && (*o)->next)
    (*o)->prev = new;
  new->next = *o;
  new->prev = NULL;
  *o = new;
}
