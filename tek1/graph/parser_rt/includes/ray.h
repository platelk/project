/*
** ray.h for ray in /home/ozouf_h//projet/rtv1/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb  1 12:23:31 2012 harold ozouf
** Last update Mon Feb  6 14:46:57 2012 harold ozouf
*/

#ifndef		RAY_H__
# define	RAY_H__

# include	"struct.h"

t_inter	*ray(t_pos *vector, t_pos *pt, t_shape *obj, t_inter *it);

#endif
