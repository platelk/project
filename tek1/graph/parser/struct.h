/*
** struct.h for struct in /home/ozouf_h//projet/rtv1
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Jan 31 15:15:01 2012 harold ozouf
** Last update Sun Mar 11 20:38:35 2012 harold ozouf
*/

#ifndef		STRUCT_H__
# define	STRUCT_H__

# define	MIN(x, y)	(((x) < (y)) ? (x) : (y))

# define	SIZE_X		1500
# define	SIZE_Y		900
# define	DIST_SCREEN		1000
# define	SPHERE			1
# define	PLANE			2
# define	CYLINDER		3
# define	CONE			4
# define	PARABOLOIDE		5

# define	OBJ_SPH		((t_sphere *)s->arg)
# define	OBJ_CON		((t_cone *)s->arg)
# define	OBJ_CYL		((t_cylinder *)s->arg)
# define	OBJ_PLN		((t_plan *)s->arg)

typedef	struct	s_color
{
  double	r;
  double	g;
  double	b;
} t_color;

typedef	struct	s_pos
{
  double	x;
  double	y;
  double	z;
} t_pos;

typedef struct	s_lum
{
  t_pos		*p;
  t_color	*c;
  struct s_lum	*next;
} t_lum;

typedef	struct s_material
{
  double	q_shi;
  t_color	*c;
} t_material;

typedef	struct	s_shape
{
  t_pos			*pos;
  t_pos			*rot;
  void			*arg;
  t_material		*mat;
  void			(*get_normal)(struct s_shape *this, t_pos *p, t_pos **n);
  void			(*destruct)(struct s_shape *this);
  double		(*inter)(struct s_shape *this, t_pos *v, t_pos *p);
  struct s_shape	*next;
} t_shape;

typedef struct	s_inter
{
  t_pos			*pt;
  t_pos			*vec;
  t_color		*c;
  double		k;
  double		q_shi;
  t_pos			*impact;
  t_pos			*vec_lum;
  t_pos			*rot;
  t_pos			*vec_normal;
  t_shape		*sh;
} t_inter;

typedef struct	s_sphere
{
  double	radius;
} t_sphere;

typedef struct	s_cylinder
{
  double	radius;
} t_cylinder;

typedef struct	s_cone
{
  double	angle;
} t_cone;

typedef struct	s_plan
{
  t_pos		*max;
  t_pos		*min;
} t_plan;

typedef	struct	s_scene
{
  t_shape	*obj;
  t_lum		*lum;
  t_pos		*eyes;
  t_pos		*rotation;
  int		fov;
  int		anti;
} t_scene;

typedef struct s_px
{
  int           x;
  int           y;
  t_color       *c;
} t_px;

typedef struct s_img
{
  int   b;
  int   e;
  int   s;
  char  *img;
  void  *img_ptr;
} t_img;

typedef	struct	s_gl
{
  t_img		*i;
  void		*mlx_ptr;
  void		*win_ptr;
  t_scene	*sc;
} t_gl;

#endif
