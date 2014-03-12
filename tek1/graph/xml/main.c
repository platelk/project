/*
** main.c for xml in /home/vink/projet/graph/xml
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue May 22 12:28:56 2012 kevin platel
** Last update Tue May 22 12:29:09 2012 kevin platel
*/


#include	<unistd.h>
#include	<stdio.h>

#include	"xml_parser.h"
#include	"xml_tree.h"
#include	"xml_chr.h"

int	main(int ac, char **av)
{
  t_xtree	*tree;

  if (ac > 1)
    tree = xml_parser(av[1]);
  tree = tree;
  av = av;
  return (0);
}
