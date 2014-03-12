/*
** server_client_id.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu May  3 08:53:38 2012 ronan guiho
** Last update Fri May  4 16:07:58 2012 ronan guiho
*/

#include <stdlib.h>

#include "client.h"

t_client *list;

t_client	*server_client_id(int id)
{
  t_client	*tmp;

  tmp = list;
  while (tmp)
    {
      if (tmp->id == id)
	return (tmp);
      tmp = tmp->next;
    }
  return (tmp);
}
