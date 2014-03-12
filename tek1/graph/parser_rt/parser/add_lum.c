/*
** lum.c for lum in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Fri Feb 17 09:15:10 2012 harold ozouf
** Last update Fri Feb 17 14:38:52 2012 harold ozouf
*/

#include	<string.h>
#include	"xfnt.h"
#include	"struct.h"
#include	"add_lum.h"

void    new_lum(t_lum **s, t_pos *p, t_color *c)
{
  t_lum *lum;

  lum = xmalloc(sizeof(*lum));
  lum->p = xmalloc(sizeof(t_pos));
  lum->c = xmalloc(sizeof(t_color));
  memcpy(lum->c, c, sizeof(t_color));
  memcpy(lum->p, p, sizeof(t_pos));
  lum->next = *s;
  *s = lum;
}
