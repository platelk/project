/*
** server_client_core.c for server in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat May  5 12:18:44 2012 ronan guiho
** Last update Sun Jun  3 08:31:47 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

int	server_client_core(t_client *client)
{
  int	rtrn;
  char	buffer[1024];

  if ((rtrn = recv(client->sock, buffer, 1024, 0)) <= 0)
    return (EXIT_FAILURE);
  buffer[rtrn] = '\0';
  client->core = my_getnbr(buffer);
  my_printf("[*] Raytracer: Clustering: CORE Receive [%d] from %s:%d.\n", \
	 client->core, inet_ntoa(client->csin->sin_addr), \
	 htons(client->csin->sin_port));
  return (EXIT_SUCCESS);
}
