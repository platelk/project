/*
** vect.h for vect in /home/ozouf_h//projet/rtv1
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Jan 31 21:10:30 2012 harold ozouf
** Last update Thu Mar  8 11:53:02 2012 harold ozouf
*/

#ifndef		VECT_H__
# define	VECT_H__

# include	"struct.h"

void	vect_dir(t_pos **vect, double x, double y);
void	get_vect(t_pos *p1, t_pos *p2, t_pos **v_res);
#endif
