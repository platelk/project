/*
** main.c for main in /home/vink/projet/graph/parser_rt/parser
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 25 14:26:29 2012 kevin platel
** Last update Tue May  1 09:06:43 2012 kevin platel
*/

#include	"parser.h"
#include	"get_scene.h"

int	main(int ac, char **av)
{
  if (ac > 1)
    get_scene(av[1]);
  return (0);
}
