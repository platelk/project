/*
** server_client_connected.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  2 14:22:20 2012 ronan guiho
** Last update Sun Jun  3 08:31:37 2012 ronan guiho
*/

#include <stdlib.h>

#include "client.h"
#include "server.h"

int	server_client_connected_suite(char *id,
				      t_client *client)
{
  pthread_t	thread_recv;

  if ((send(client->sock, id, my_strlen(id), 0)) == SOCKET_ERROR)
    {
      my_printf("Raytracer: Clustering: Error: Send [ID] failure.\n");
      return (EXIT_FAILURE);
    }
  my_printf("[*] Raytracer: Clustering: Send [ID = %s] to %s:%d\n", id, \
	 inet_ntoa(client->csin->sin_addr), htons(client->csin->sin_port));
  if ((server_client_core(client)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((pthread_create(&thread_recv, NULL, server_client_receive, \
		      &client->id)) < 0)
    {
      my_printf("Raytracer: Clustering: Error: Failed to start service\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
int	server_client_connected(t_client **list, SOCKET ssock)
{
  t_client	*client;
  char		*id;

  if ((client = server_client_create()) == NULL)
    return (EXIT_FAILURE);
  if ((client->sock = accept(ssock, (struct sockaddr *)client->csin,
			     (socklen_t *)&client->size_csin)) == SOCKET_ERROR)
    {
      my_printf("Raytracer: Clustering: Error: Accept dysfunction.\n");
      return (EXIT_FAILURE);
    }
  my_printf("[*] Raytracer: Clustering: Client [%s:%d], Connected [%d].\n", \
	 inet_ntoa(client->csin->sin_addr), htons(client->csin->sin_port), \
	 client->sock);
  server_client_add(list, client);
  if ((id = server_int_to_str(client->id)) == NULL)
    return (EXIT_FAILURE);
  server_client_connected_suite(id, client);
  return (EXIT_SUCCESS);
}
