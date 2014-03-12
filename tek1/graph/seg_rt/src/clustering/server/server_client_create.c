/*
** server_client_create.c for server in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  2 13:28:40 2012 ronan guiho
** Last update Tue May  8 14:34:01 2012 ronan guiho
*/

#include <stdlib.h>

#include "client.h"

t_client	*server_client_create()
{
  static int	id;
  t_client	*client;

  if ((client = malloc(sizeof(*client))) == NULL)
    return (NULL);
  if ((client->csin = malloc(sizeof(*client->csin))) == NULL)
    return (NULL);
  client->id = id++;
  client->size_csin = sizeof(*client->csin);
  client->ping = 1;
  client->core = 0;
  client->latence = 0;
  client->status = 0;
  client->next = NULL;
  return (client);
}
