/*
** server_distribution_send.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat May  5 16:46:57 2012 ronan guiho
** Last update Fri Jun  1 11:04:22 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

t_client	*list;

char		*server_distribution_send_plage(int x0,
						int x1)
{
  char		*buffer;
  char		*buffer_x0;
  char		*buffer_x1;

  if ((buffer_x0 = server_int_to_str(x0)) == NULL)
    return (NULL);
  if ((buffer_x1 = server_int_to_str(x1)) == NULL)
    return (NULL);
  if ((buffer = my_strconcat(buffer_x0, "-")) == NULL)
    return (NULL);
  if ((buffer = my_strconcat(buffer, buffer_x1)) == NULL)
    return (NULL);
  free(buffer_x0);
  free(buffer_x1);
  return (buffer);
}

int		server_distribution_send()
{
  t_client	*tmp_client;
  t_plage	*tmp_plage;
  char		*trame;

  tmp_client = list;
  while (tmp_client)
    {
      tmp_plage = tmp_client->plage;
      while (tmp_plage)
	{
	  if ((trame = server_distribution_send_plage(tmp_plage->X_start,
						      tmp_plage->X_end))
	      == NULL)
	    return (EXIT_FAILURE);
	  if ((send(tmp_client->sock, trame, my_strlen(trame), 0)) <= 0)
	    return (EXIT_FAILURE);
	  tmp_plage = tmp_plage->next;
	  free(trame);
	}
      tmp_client->status = 1;
      tmp_client = tmp_client->next;
    }
  return (EXIT_SUCCESS);
}
