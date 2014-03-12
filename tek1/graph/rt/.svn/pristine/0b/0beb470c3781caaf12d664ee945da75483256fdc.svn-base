/*
** add_obj_parse.c for parse_add_obj in /home/ozouf_h//rt/src/parse_obj
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sun Jun  3 19:11:36 2012 harold ozouf
** Last update Sun Jun  3 19:21:56 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"my_strtok.h"
#include	"my.h"
#include	"parse_obj.h"

void	add_vertice(t_vertice **v, double x, double y, double z)
{
  t_vertice	*new;

  new = malloc(sizeof(*new));
  new->pos[0] = x;
  new->pos[1] = y;
  new->pos[2] = z;
  new->next = *v;
  *v = new;
}

void	add_vertice_norme(t_vertice_n **vn,
				  double x, double y, double z)
{
  t_vertice_n	*new;

  new = malloc(sizeof(*new));
  new->pos[0] = x;
  new->pos[1] = y;
  new->pos[2] = z;
  new->next = *vn;
  *vn = new;
}

void	add_face(t_face **f, char *x, char *y, char *z)
{
  t_face	*new;
  char		**sep;

  new = malloc(sizeof(*new));
  sep = my_strtok(x, "/", TOK_DELIM);
  new->n = my_getnbr(sep[1]);
  new->pos[0] = my_getnbr(sep[0]);
  sep = my_strtok(y, "/", TOK_DELIM);
  new->pos[1] = my_getnbr(sep[0]);
  sep = my_strtok(z, "/", TOK_DELIM);
  new->pos[2] = my_getnbr(sep[0]);
  new->next = *f;
  *f = new;
}

