/*
** get_scene.c for get_scene in /home/ozouf_h//projet/rtv1/srcs/raytrace
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Mon Mar  5 20:19:56 2012 harold ozouf
** Last update Sun Mar 11 14:57:34 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"struct.h"
#include	"node.h"
#include	"aff.h"
#include	"xfnt.h"
#include	"build_tree.h"
#include	"fill_scene.h"
#include	"parser.h"
#include	"get_scene.h"

t_scene		*get_scene(char *path)
{
  t_node        *root;
  t_scene       *sc;
  char		*xml;

  xml = parser(path);
  if (xml != NULL)
    {
      root = NULL;
      sc = xmalloc(sizeof(*sc));
      my_putstr("Parsing: \t\tOK");
      add_node(&root, "root", xml);
      my_putstr("Adding node root: \tOK");
      build_tree(&root);
      my_putstr("Building tree: \t\tOK");
      fill_scene(&sc, root);
      my_putstr("Fill_scene: \t\tOK");
      free(xml);
      return (sc);
    }
  return (NULL);
}
