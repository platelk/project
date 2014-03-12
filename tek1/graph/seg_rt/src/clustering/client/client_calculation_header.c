/*
** client_calculation_header.c for client in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May  6 12:29:02 2012 ronan guiho
** Last update Mon May  7 00:41:00 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

char	*client_calculation_header(int x, int y0, int y1)
{
  char	*tmp;
  char	**tab;
  char	*header;

  if ((tab = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  if (y0 < 0)
    y0 = 0;
  tab[0] = server_int_to_str(x);
  tab[1] = server_int_to_str(y0);
  tab[2] = server_int_to_str(y1);
  header = my_strconcat(tab[0], "-");
  tmp = header;
  header = my_strconcat(header, tab[1]);
  free(tmp);
  tmp = header;
  header = my_strconcat(header, "-");
  free(tmp);
  header = my_strconcat(header, tab[2]);
  return (header);
}
