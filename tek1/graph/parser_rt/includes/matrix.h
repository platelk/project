/*
** matrix.h for matrix in /home/ozouf_h//projet/rtv1/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Thu Feb  9 15:20:10 2012 harold ozouf
** Last update Mon Feb 20 10:57:27 2012 harold ozouf
*/

#ifndef		MATRIX_H__
# define	MATRIX_H__

#include	"struct.h"

double	**create_3x3_matrix(void);
t_pos  *matrix_mult_1x3(double **m1, t_pos *m2);
void	free_matrix_3x3(double **mat);
#endif
