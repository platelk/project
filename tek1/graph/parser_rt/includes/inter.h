/*
** list_inter.h for list_inter\ in /home/ozouf_h//projet/rtv1/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Thu Feb  2 20:40:16 2012 harold ozouf
** Last update Sat Mar 10 23:32:30 2012 harold ozouf
*/

#ifndef		LIST_INTER_H__
# define	LIST_INTER_H__

#include	"struct.h"

t_inter	*create_inter(void);
void	free_inter(t_inter *it);
void	get_min(t_inter *it, double k, t_pos *vec, t_shape *o);
void	add_in_inter(t_inter **it, double k, t_shape *o, t_pos *vec);

#endif
