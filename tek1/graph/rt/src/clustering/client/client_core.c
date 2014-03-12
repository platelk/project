/*
** client_core.c for client in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat May  5 00:03:16 2012 ronan guiho
** Last update Sun Jun  3 08:38:09 2012 ronan guiho
*/

#include <stdlib.h>
#include <unistd.h>

#include "server.h"

SOCKET	csock;

int	client_core()
{
  int	core;
  char	*core_send;

  core = sysconf(_SC_NPROCESSORS_CONF);
  if ((core_send = server_int_to_str(core)) == NULL)
    return (EXIT_FAILURE);
  if ((send(csock, core_send, my_strlen(core_send), 0)) == SOCKET_ERROR)
    {
      my_printf("Raytracer: Clustering: Error: Send [CORE] failure.\n");
      return (EXIT_FAILURE);
    }
  my_printf("[*] Raytracer: Clustering: Send [CORE = %s] to [SERVER].\n",
	 core_send);
  return (EXIT_SUCCESS);
}
