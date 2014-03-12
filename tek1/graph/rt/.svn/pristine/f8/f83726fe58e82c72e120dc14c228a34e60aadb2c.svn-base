/*
** parse.c for parse in /home/ozouf_h//rt/parser_3ds
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Thu May 31 23:59:03 2012 harold ozouf
** Last update Sun Jun  3 19:23:32 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"my.h"
#include	"get_next_line.h"
#include	"my_strtok.h"
#include	"object.h"
#include	"init_triangle.h"
#include	"my_rev_list.h"
#include	"parse_obj.h"

static	int	size_tab(char **tab)
{
  int	i;

  i = 0;
  while (tab[i])
    i++;
  return (i);
}

int	get_coord(char *path, t_vertice **v, t_vertice_n **vn, t_face **f)
{
  int	fd;
  char	*buff;
  char	**sep;

  fd = open(path, O_RDONLY);
  if (fd == -1)
    exit(1);
  while ((buff = get_next_line(fd)))
    {
      sep = my_strtok(buff, " ", TOK_DELIM);
      if (sep && size_tab(sep) == 4)
	{
	  if (!my_strcmp("v", sep[0]))
	    add_vertice(v, atof(sep[1]), atof(sep[2]),
			atof(sep[3]));
	  else if (!my_strcmp("f", sep[0]))
	    add_face(f, sep[1], sep[2], sep[3]);
	  else if (!my_strcmp("vn", sep[0]))
	    add_vertice_norme(vn, atof(sep[1]), atof(sep[2]),
			      atof(sep[3]));
	}
    }
  close(fd);
 return (1);
}

static double	*get_itm(t_vertice *v, t_vertice_n *vn, int flag, int src)
{
  t_vertice	*tmpv;
  t_vertice_n	*tmpvn;
  int		i;

  i = 0;
  tmpv = v;
  tmpvn = vn;
  if (flag)
    {
      while (++i < src && tmpv)
	tmpv = tmpv->next;
      return ((tmpv) ? (tmpv->pos) : (NULL));
    }
  while (++i < src && tmpvn)
    tmpvn = tmpvn->next;
  return ((tmpvn) ? (tmpvn->pos) : (NULL));
}

static	void	get_object_from_file(char *path,
				     t_object **o, t_object *parent)
{
  t_face		*f;
  t_vertice       	*v;
  t_vertice_n     	*vn;
  double		pt[3][3];
  double		n[3];

  f = NULL;
  v = NULL;
  vn = NULL;
  get_coord(path, &v, &vn, &f);
  my_rev_list(&v);
  my_rev_n(&vn);
  my_rev_f(&f);
  while (f)
    {
      if (copy_tab(pt[0], get_itm(v, vn, 1, f->pos[0])) &&
	  copy_tab(pt[1], get_itm(v, vn, 1, f->pos[1])) &&
	  copy_tab(pt[2], get_itm(v, vn, 1, f->pos[2])) &&
	  copy_tab(n, get_itm(v, vn, 0, f->n)))
	add_triangle(o, pt, n, parent);
      f = f->next;
    }
}

void	parse_3ds(t_object **o)
{
  t_object	*tmp;
  t_object	*toto;
  t_object	*it;

  tmp = *o;
  while (tmp)
    {
      if (tmp->type == BLENDER && tmp->son)
	{

	  get_object_from_file(((t_blender *)tmp->son)->path, o, tmp);
	  toto = *o;
	  it = tmp->next;
	  if (tmp->prev)
	    tmp->prev->next = tmp->next;
	  if (tmp->next)
	    tmp->next->prev = tmp->prev;
	  if (*o == tmp)
	    *o = tmp->next;
	}
      else
	it = tmp->next;
      tmp = it;
    }
}
