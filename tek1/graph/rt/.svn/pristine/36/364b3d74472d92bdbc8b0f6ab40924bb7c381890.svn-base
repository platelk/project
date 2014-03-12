/*
** client_main.c for client in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 11:01:10 2012 ronan guiho
** Last update Sun Jun  3 08:37:11 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "client.h"

SOCKET		csock;

int			client_main(char *ip, int port)
{
  int			retrn;
  struct sockaddr_in 	*csin;
  char			buffer[1024];

  csock = socket(AF_INET, SOCK_STREAM, 0);
  if ((csin = client_sockaddr_create(ip, port)) == NULL)
    return (EXIT_FAILURE);
  if ((connect(csock, (struct sockaddr *)csin, sizeof(*csin))) == SOCKET_ERROR)
    {
      my_printf("Raytracer: Clustering: Error: Connection unavaible.\n");
      return (EXIT_FAILURE);
    }
  my_printf("[*] Raytracer: Clustering: Connection %s:%d.\n", ip, port);
  if ((retrn = recv(csock, buffer, 1024, 0)) == SOCKET_ERROR)
    return (EXIT_FAILURE);
  buffer[retrn] = '\0';
  my_printf("[*] Raytracer: Clustering: ID Receive [%s].\n", buffer);
  if ((client_core()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  my_printf("[*] Raytracer: Clustering: Waiting...\n");
  signal(SIGINT, client_close);
  client_listen();
  return (EXIT_SUCCESS);
}
