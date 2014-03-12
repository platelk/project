/*
** server_client_remove.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu May  3 13:44:43 2012 ronan guiho
** Last update Sun Jun  3 08:32:58 2012 ronan guiho
*/

#include <stdlib.h>
#include <unistd.h>

#include "server.h"

t_client	*list;

int		server_client_remove(t_client *client)
{
  t_client	*tmp;

  tmp = list;
  if (tmp == client)
    list = client->next;
  else
    {
      while (tmp)
	{
	  if (tmp->next != NULL)
	    {
	      if (tmp->next == client)
		tmp->next = client->next;
	    }
	  tmp = tmp->next;
	}
    }
  my_printf("[*] Raytracer: Clustering: Client [%s:%d], Disconnected.\n", \
	 inet_ntoa(client->csin->sin_addr), htons(client->csin->sin_port));
  close(client->sock);
  return (EXIT_SUCCESS);
}
