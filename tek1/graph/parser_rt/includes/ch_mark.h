/*
** ch_mark.h for ch_mark in /home/ozouf_h//projet/rtv1/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Thu Feb  9 15:48:21 2012 harold ozouf
** Last update Sun Mar 11 14:38:04 2012 harold ozouf
*/

#ifndef		CH_MARK_H__
# define	CH_MARK_H__

#include	"struct.h"

t_pos	*ch_mark(t_pos *obj, t_pos *pt, t_pos *new);
t_pos	*ch_rota(t_pos *pt, t_shape *sh, t_pos *new);
t_pos	*ch_rotation(t_pos *pt, t_pos *rot, t_pos *new);

#endif
