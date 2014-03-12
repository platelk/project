/*
** header.h for Export BMP in /home/guiho_r/tek1/rtv1/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat Mar 31 16:46:10 2012 ronan guiho
** Last update Sat Mar 31 22:34:33 2012 ronan guiho
*/

#ifndef __HEADER_H__
#define __HEADER_H__

typedef struct s_header
{
  int		img_size;
  int		reserved1;
  int		addr_begin;
  int		size_part;
  int		width_image;
  int		height_image;
  int		plan_bpp;
  int		compression;
  int		size_data;
  int		reso_horizon;
  int		reso_vertical;
  int		nb_color_use;
  int		nb_color_imp;
} t_headerbmp;

typedef struct s_quadcolor
{
  unsigned char B;
  unsigned char G;
  unsigned char R;
  unsigned char A;
} t_colorbmp;

#endif
