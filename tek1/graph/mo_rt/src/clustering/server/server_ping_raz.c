/*
** server_ping_raz.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu May  3 09:35:18 2012 ronan guiho
** Last update Thu May  3 09:46:14 2012 ronan guiho
*/

#include <stdlib.h>

#include "client.h"

t_client	*list;

int		server_ping_raz()
{
  t_client	*tmp;

  tmp = list;
  while (tmp)
    {
      tmp->ping = 0;
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}
