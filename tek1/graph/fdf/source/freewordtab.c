/*
** freewordtab.c for freewordtab.c in /home/platel_k/projet/fdf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Nov 17 17:22:54 2011 kevin platel
** Last update Tue Dec  6 13:08:06 2011 kevin platel
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

void	freewordtab(char ***tab)
{
  int	i;

  i = 0;
  while (*tab[i] != NULL)
    {
      free(*tab[i]);
      i++;
    }
  free(*tab);
}
