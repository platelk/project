/*
** main.c for lem_in in /home/leprov_a//depot/lemin/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr  2 09:31:15 2012 alexis leprovost
** Last update Fri Apr 20 17:29:32 2012 matthieu przybylski
*/

#include	<stdlib.h>

#include	"lemin.h"

int	main(void)
{
  t_glob	*glob;

  if ((glob = parser_main()) == NULL)
    return (EXIT_FAILURE);
  if (weighting(glob) == NULL)
    return (0);
  path_finding(glob);
  return (EXIT_SUCCESS);
}
