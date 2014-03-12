/*
** fill_struct_scene.c for fill_struct_scene in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 23:29:12 2012 harold ozouf
** Last update Mon Mar  5 22:00:42 2012 harold ozouf
*/

#include	<stdio.h>
#include	"convert.h"
#include	"finding_elm.h"
#include	"fill_struct_scene.h"

void	fill_pos(t_pos **p, t_node *node)
{
  (*p)->x = to_double(get_value(get_node("x", node)));
  (*p)->y = to_double(get_value(get_node("y", node)));
  (*p)->z = to_double(get_value(get_node("z", node)));
}

void	fill_color(t_color **c, t_node *node)
{
  (*c)->r = to_double(get_value(get_node("r", node)));
  (*c)->g = to_double(get_value(get_node("g", node)));
  (*c)->b = to_double(get_value(get_node("b", node)));
}
