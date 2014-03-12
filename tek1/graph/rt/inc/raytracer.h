/*
** raytracer.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri May  4 14:06:13 2012 alexis leprovost
** Last update Sun Jun  3 19:12:00 2012 alexis leprovost
*/

#ifndef __RAYTRACER_H__
#define __RAYTRACER_H__

#include	<stdlib.h>

#define	NB_DIMENSION	3
#define	EPSILON	0.001

#define	NORMAL_ERROR	0.001

#define CONST_SPEC	2.000
#define CONST_SHAD	5.000
#define	CONST_REFL      10
#define	CONST_TRANS	50
#define	CONST_MATERIAL	1.0F
#define	CONST_WIZZ	500.0F

#define	CONST_ERROR	0.000001F
#define	CONST_NORMAL	0.001F

#define	ECHANTILLON	0.500
#define	NROOKS	4.000

#define	CONVERT_DEGREE(value)		(((value) / 180.0F) * M_PI)
#define	CONVERT_RADIAN(value)		(((value) / M_PI) * 180.0F)
#define	CAST(value)	((value) > 255.000 ? 255.000 : \
			 (value) < 0.000 ? 0.000 : (value))
#define RL(value)	((double)((random() % 5) * 0.1) + value)
#define	ABS(value)	((value) < 0 ? ((value) * (-1.0)) : (value))
#define CARRE(value)	((value) * (value))
#define CUBE(value)	((value) * (value) * (value))
#define QUATRO(value)   ((value) * (value) * (value) * (value))
#define SMALLER_POSITIVE_NUMBER(v1, v2)	((v1) < (v2) ? \
					 ((v1) >= 0.000 ? (v1) : (v2)) : \
					 ((v2) >= 0.000 ? (v2) : (v1)))

typedef enum e_coord
{
  X,
  Y,
  Z
} t_coord;

typedef enum e_dom
{
  MIN,
  MAX
} t_dom;

#endif
