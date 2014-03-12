/*
** client_sockaddr_createw.c for client in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 11:21:28 2012 ronan guiho
** Last update Tue May  1 11:52:12 2012 ronan guiho
*/

#include <stdlib.h>

#include "client.h"

struct sockaddr_in	*client_sockaddr_create(char *ip, int port)
{
  struct sockaddr_in	*csin;

  if ((csin = malloc(sizeof(*csin))) == NULL)
    return (NULL);
  csin->sin_addr.s_addr = inet_addr(ip);
  csin->sin_family = AF_INET;
  csin->sin_port = htons(port);
  return (csin);
}
