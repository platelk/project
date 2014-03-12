/*
** client_main.c for client in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 11:01:10 2012 ronan guiho
** Last update Mon May  7 00:45:30 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

#include "client.h"

SOCKET		csock;

/* TEST LIBX */
int TEST_RED;
int TEST_GREEN;
int TEST_BLUE;
/*==========*/

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
      printf("Raytracer: Clustering: Error: Connection TimeOut.\n");
      return (EXIT_FAILURE);
    }
  printf("[*] Raytracer: Clustering: Connection %s:%d.\n", ip, port);
  if ((retrn = recv(csock, buffer, 1024, 0)) == SOCKET_ERROR)
    {
      printf("Raytracer: Clustering: Error: Receive ID failed.\n");
      return (EXIT_FAILURE);
    }
  buffer[retrn] = '\0';
  printf("[*] Raytracer: Clustering: ID Receive [%s].\n", buffer);
  if ((client_core()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  printf("[*] Raytracer: Clustering: Waiting...\n");
  signal(SIGINT, client_close);
  client_listen();
  return (EXIT_SUCCESS);
}

int	main(int ac, char **av)
{
  (void)ac;
  TEST_RED = my_getnbr(av[3]);
  TEST_GREEN = my_getnbr(av[4]);
  TEST_BLUE = my_getnbr(av[5]);
  if ((client_main(av[1], atoi(av[2]))) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
