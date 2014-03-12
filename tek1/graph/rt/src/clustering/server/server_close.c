/*
** server_close.c for server in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  2 18:48:14 2012 ronan guiho
** Last update Sun Jun  3 08:33:10 2012 ronan guiho
*/

#include <stdlib.h>
#include <unistd.h>

#include "server.h"

SOCKET		ssock;
t_client	*list;

void		server_close(int seg)
{
  t_client	*tmp;

  (void)seg;
  my_putchar('\n');
  tmp = list;
  while (tmp)
    {
      server_client_remove(tmp);
      tmp = tmp->next;
    }
  close(ssock);
  my_printf("\n[*] Raytracer: Clustering: Server disconnect.\n");
  exit(EXIT_FAILURE);
}
