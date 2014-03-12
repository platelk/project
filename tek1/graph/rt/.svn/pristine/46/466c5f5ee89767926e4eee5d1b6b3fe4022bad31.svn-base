/*
** server_main.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 11:02:05 2012 ronan guiho
** Last update Sun Jun  3 08:26:58 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include "image.h"
#include "mlx.h"

#include "server.h"

SOCKET		ssock;

int			server_main(int port)
{
  struct sockaddr_in	*sin;

  if ((ssock = socket(AF_INET, SOCK_STREAM, 0)) == INVALID_SOCKET)
    {
      my_printf("Raytracer: Clustering: Error: Cant create socket.\n");
      return (EXIT_FAILURE);
    }
  my_printf("[*] Raytracer: Clustering: Socket: Open(TCP/IP) ...");
  if ((sin = server_sockaddr_create(port)) == NULL)
    return (EXIT_FAILURE);
  my_printf(" \033[32mDone !\033[00m\n");
  if ((bind(ssock, (struct sockaddr *)sin, sizeof(*sin))) == SOCKET_ERROR)
    {
      my_printf("Raytracer: Clustering: Error: Port already use.\n");
      return (EXIT_FAILURE);
    }
  signal(SIGINT, server_close);
  if ((listen(ssock, MAX_CLIENT)) == SOCKET_ERROR)
    return (EXIT_FAILURE);
  if ((server_listen(ssock)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
