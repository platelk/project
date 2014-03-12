/*
** free.h for raytracer in /home/leprov_a//depot/rt/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed May  2 18:16:53 2012 alexis leprovost
** Last update Mon May  7 12:39:18 2012 alexis leprovost
*/

#ifndef __FREE_H__
#define __FREE_H__

#include	"global.h"
#include	"window.h"
#include	"image.h"
#include	"color.h"
#include	"parse.h"

void            free_global(t_global *global);
void            free_window(t_window *window);
void            free_image(t_image *image);
void		free_info(t_info *inf);

#endif
