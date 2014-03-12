/*
** server_client_receive.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu May  3 08:45:13 2012 ronan guiho
** Last update Wed May 23 16:02:43 2012 ronan guiho
*/

#include <string.h>
#include <stdlib.h>

#include "server.h"

t_client *list;

int			server_client_receive_action(t_client *client, \
						     char *buffer)
{
  struct timeval	tv1;
  pthread_t		thread_action;

  if (my_strcmp(buffer, "PONG") == 0)
    {
      gettimeofday(&tv1, NULL);
      client->latence = tv1.tv_usec - client->tv.tv_usec;
      client->ping = 1;
    }
  else
    {
      if ((pthread_create(&thread_action, NULL,	\
			  server_client_receive_plage, buffer)) < 0)
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}

void		*server_client_receive(void *arg)
{
  int		*id;
  int		retrn;
  char		buffer[128];
  char		*trame;
  t_client	*client;
  fd_set	rfds;

  id = (int *)arg;
  trame = my_strdup("");
  client = server_client_id(*id);
  while (42)
    {
      FD_ZERO(&rfds);
      FD_SET(client->sock, &rfds);
      select(client->sock + 1, &rfds, NULL, NULL, NULL);
      if (FD_ISSET(client->sock, &rfds))
	{
	  if ((retrn = recv(client->sock, buffer, 128, 0)) <= 0)
	    return (NULL);
	  buffer[retrn] = '\0';
	  trame = my_strconcat(trame, buffer);
	  if ((retrn = server_client_receive_is_valide(trame)) > -1)
	    {
	      server_client_receive_action(client, \
					   server_client_receive_cut_trame(trame, retrn));
	      trame = my_strdup(&trame[retrn + 1]);
	    }
	}
    }
  return (NULL);
}
