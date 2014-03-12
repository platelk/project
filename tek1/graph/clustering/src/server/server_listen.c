/*
** server_listen.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 16:06:02 2012 ronan guiho
** Last update Fri May  4 16:01:25 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "server.h"

t_client *list;

int		server_listen(SOCKET ssock)
{
  list = NULL;
  if ((server_ping_start()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((server_management_start()) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  printf("[*] Raytracer: Clustering: Listen...\n");
  while (42)
    {
      if ((server_client_connected(&list, ssock)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
