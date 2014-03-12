/*
** server_client_receive_send.c for server in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May  6 20:38:02 2012 ronan guiho
** Last update Sat Jun  2 15:23:40 2012 jordan vanwalleghem
*/

#include <stdlib.h>

#include "server.h"

int		server_client_receive_treatement(t_client *client, \
						 t_trame **trame)
{
  t_trame	*tmp;

  tmp = *trame;
  while (tmp)
    {
      if (my_strlen(tmp->buffer) == tmp->size)
	{
	  server_client_receive_action(client, tmp->buffer);
	  server_client_receive_remove(trame, tmp);
	}
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
