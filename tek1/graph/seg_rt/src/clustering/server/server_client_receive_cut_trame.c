/*
** server_client_receive_cut_trame.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon May  7 17:17:07 2012 ronan guiho
** Last update Wed May 23 16:07:33 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

char	*server_client_receive_cut_trame(char *buffer, int i)
{
  int	i1;
  char	*rtrn;

  i = 0;
  i1 = 0;
  if ((rtrn = malloc(sizeof(char) * (my_strlen(buffer)))) == NULL)
    return (NULL);
  while (buffer[i1] != 4)
    {
      rtrn[i1] = buffer[i1];
      i1++;
    }
  rtrn[i1] = '\0';
  return (rtrn);
}
