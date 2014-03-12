/*
** server_client_add.c for server in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  2 13:26:01 2012 ronan guiho
** Last update Fri May  4 15:23:00 2012 ronan guiho
*/

#include <stdlib.h>

#include "client.h"

int		server_client_add(t_client **list, t_client *client)
{
  t_client	*tmp;

  tmp = *list;
  if (*list == NULL)
    *list = client;
  else
    {
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = client;
    }
  return (EXIT_SUCCESS);
}
