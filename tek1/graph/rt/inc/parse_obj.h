/*
** parse_obj.h for parse_obj in /home/ozouf_h//rt/src/parse_obj
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Jun  1 08:09:32 2012 harold ozouf
** Last update Sun Jun  3 16:19:09 2012 kevin platel
*/

#ifndef		__PARSE_OBJ_H__
# define	__PARSE_OBJ_H__

#include	"object.h"

typedef	struct	s_vertice
{
  double		pos[3];
  struct s_vertice	*next;
} t_vertice;

typedef	struct	s_vertice_n
{
  double		pos[3];
  struct s_vertice_n	*next;
} t_vertice_n;

typedef	struct	s_face
{
  int			pos[3];
  int			n;
  struct s_face		*next;
} t_face;

void	parse_3ds(t_object **);
void	add_vertice(t_vertice **, double, double, double);
void	add_vertice_norme(t_vertice_n **, double, double, double);
void	add_face(t_face **, char *, char *, char *);

#endif
