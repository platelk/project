/*
** server_sockaddr_create.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 15:36:45 2012 ronan guiho
** Last update Wed May  2 20:37:33 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

struct sockaddr_in	*server_sockaddr_create(int port)
{
  struct sockaddr_in	*sin;

  if ((sin = malloc(sizeof(*sin))) == NULL)
    return (NULL);
  sin->sin_addr.s_addr = htonl(INADDR_ANY);
  sin->sin_family = AF_INET;
  sin->sin_port = htons(port);
  return (sin);
}
