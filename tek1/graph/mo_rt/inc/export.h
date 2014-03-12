/*
** export.h for raytracer in /home/guiho_r/tek1/rt/src/display
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu May 17 10:52:28 2012 ronan guiho
** Last update Tue May 29 18:37:34 2012 zoe phalippou
*/

#ifndef __EXPORT_H__
#define __EXPORT_H__

#include "image.h"
#include "global.h"

int		export_bmp(t_global *, char *);
t_image		*export_image(t_global *);

#endif
