/*
** get_data.c for get_data in /home/platel_k/projet/fdf/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Dec  5 16:52:58 2011 kevin platel
** Last update Fri Dec  9 14:09:23 2011 kevin platel
*/

#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "grille.h"
#include "mlx.h"
#include "point.h"
#include "my_libX.h"
#include "my.h"
#include "fdf.h"

t_grille	*get_data(char *link, int *i, int *j)
{
  int	fd;
  char	*line;
  char	**pars;
  t_grille	*grille;

  fd = open(link, O_RDONLY);
  *j = 0;
  grille = NULL;
  while ((line = get_next_line(fd)))
    {
      pars = my_str_to_wordtab(line);
      (*i) = -1;
      while (pars[++*i] != '\0' && ((*i)) < WIDTH)
	grille = add_new(grille, (*i), (*j), my_getnbr(pars[(*i)]) / 2);
      free(line);
      (*j)++;
    }
  return (grille);
}
