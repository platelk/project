/*
** server_client_receive_send.c for server in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May  6 20:38:02 2012 ronan guiho
** Last update Mon May  7 15:40:10 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

int		server_client_receive_treatement(t_client *client, \
						 t_trame **trame)
{
  int		i;
  t_trame	*tmp;

  i = 0;
  tmp = *trame;
  while (tmp)
    {
      /*      printf("==============-- TRAME --================\n");
      printf("Current_Size = %d\n", my_strlen(tmp->buffer));
      printf("Max_Size = %d\n", tmp->size);
      printf("Buffer = %s\n", tmp->buffer);*/
      if (my_strlen(tmp->buffer) == tmp->size)
	{
	  server_client_receive_action(client, tmp->buffer);
	  server_client_receive_remove(trame, tmp);
	}
      //      printf("=========================================\n");
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
