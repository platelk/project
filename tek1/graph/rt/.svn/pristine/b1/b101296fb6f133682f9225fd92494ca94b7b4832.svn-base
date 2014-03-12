/*
** client_calculation_buffer.c for clizen in /home/guiho_r/tek1/rt/src/obj
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jun  1 10:19:52 2012 ronan guiho
** Last update Fri Jun  1 10:49:49 2012 ronan guiho
*/

#include <stdlib.h>

#include "my.h"
#include "global.h"
#include "color.h"
#include "parse.h"
#include "server.h"
#include "thread.h"
#include "display.h"

char	*client_calculation_buffer_tab(char **tab)
{
  char		*tmp;
  char		*buffer;

  buffer = my_strdup("-");
  tmp = buffer;
  buffer = my_strconcat(buffer, tab[0]);
  free(tmp);
  tmp = buffer;
  buffer = my_strconcat(buffer, "/");
  free(tmp);
  tmp = buffer;
  buffer = my_strconcat(buffer, tab[1]);
  free(tmp);
  tmp = buffer;
  buffer = my_strconcat(buffer, "/");
  free(tmp);
  tmp = buffer;
  buffer = my_strconcat(buffer, tab[2]);
  free(tmp);
  free(tab[0]);
  free(tab[1]);
  free(tab[2]);
  return (buffer);
}

char		*client_calculation_buffer(t_color *color)
{
  char		**tab;
  char		*buffer;

  if ((tab = malloc(sizeof(char *) * 3)) == NULL)
    return (NULL);
  tab[0] = server_int_to_str(color->red);
  tab[1] = server_int_to_str(color->green);
  tab[2] = server_int_to_str(color->blue);
  buffer = client_calculation_buffer_tab(tab);
  return (buffer);
}
