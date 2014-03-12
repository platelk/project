/*
** wolf.h for wolf.h in /home/platel_k/projet/graph/wolf3d/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Jan  4 09:54:35 2012 kevin platel
** Last update Sun Mar 11 14:54:49 2012 kevin platel
*/

#ifndef __RT_H__
#define __RT_H__

#include "mlx.h"
#include "scene.h"
#include "camera.h"
#include "object.h"
#include "attribute.h"
#include "point.h"

#define	COLOR	(0x00FF0000)
#define FOV	(200)

#define	FOV_STR	("dist")
#define COL_STR ("color")

#define	OPEN_CHAR ('<')
#define	CLOSE_CHAR ('>')

enum
{
    SPHERE= 1,
    PLAN = 2,
    CONE = 4,
    CYL = 8
};

typedef union u_color
{
  unsigned int	color;
  unsigned char	tab[3];
} t_color;

typedef struct s_param
{
  void	*mlx_ptr;
  void	*win_ptr;
  t_imag	*img;
} t_param;

t_point	        *rotate_x(t_point *coor, double ang);
t_point		*rotate(t_point *p, t_cam *parm);
t_point	        *rotate_y(t_point *coor, double ang);
t_point	        *rotate_z(t_point *coor, double ang);
t_point		*inv_rotate(t_point *p, t_cam *parm);

t_imag	*creat_img(t_scene *scene, void *mlx_ptr);
t_imag	*calc_img(t_scene *scene, void *mlx_ptr);
double	*calc_vect(t_point *point);
double	calc_sph(t_object *object, double *vect, t_cam *cam);
double	calc_k(t_object *object, t_point *point, t_cam *cam);
int	check_balise(char *line, char *name);
void	print_balise_error(int error);
t_attr	*new_attr(t_attr *attr, char *name, char *value, void *father);
t_attr	*get_attr(char *line, void *father);
t_cam   *new_cam(char *name, t_cam *cam, void *father);
char	*get_cam(int fd, t_cam **cam, void *father);
t_scene	*get_data(char *path);
int	get_type(char *line);
t_object    *new_object(char *name, t_object *obj, void *father);
char	*get_object(int fd, t_object **obj, void *father);
t_cam	*get_pos(t_cam *new, t_attr *attr);
t_object	*get_pos_obj(t_object *new, t_attr *attr);
t_scene	*get_scene(int fd, char *buffer);
char	*search_attr(t_attr *attr, char *str);
int	search_coli(t_scene *scene, t_cam *cam, t_point *point);
t_attr	*new_attr(t_attr *attr, char *name, char *value, void *father);
t_attr	*get_attr(char *line, void *father);
int	calc_light(t_object *obj, double *vect, t_scene *scene, double rk);
int	calc_color_ombre(double k, int color, int mode);
int	calc_color_light(t_object *obj, t_cam *cam, t_point *p, double mod);
t_light *new_light(char *name, t_light *obj, void *father);
char	*get_light(int fd, t_light **light, void *father);
t_light	*get_pos_light(t_light *new, t_attr *attr);
double	 search_k(t_scene *scene, t_cam *cam, t_point *point, t_object **tmp);
t_point	*calc_scalaire(t_object *obj, t_point *point);
int     calc_color(t_object *obj, t_color color, double cos, double k);
t_point *calc_scalaire(t_object *obj, t_point *point);
int     moy_col(int color, int old);
double	calc_delta_cone(t_object *object, double *vect, t_cam *cam);
double	calc_delta_cyl(t_object *object, double *vect, t_cam *cam);
double	calc_delta_sph(double *vect, t_object *object, t_cam *cam);

#endif
