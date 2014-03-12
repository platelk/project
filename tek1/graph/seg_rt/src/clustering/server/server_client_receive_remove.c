/*
** server_client_receive_remove.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May  6 20:51:08 2012 ronan guiho
** Last update Sun May  6 21:42:33 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

int		server_client_receive_remove(t_trame **list_trame, \
					     t_trame *tmp)
{
  t_trame	*tmp_list;

  tmp_list = *list_trame;
  if (tmp_list == tmp)
    {
      *list_trame = tmp->next;
      return (EXIT_SUCCESS);
    }
  while (tmp_list)
    {
      if (tmp_list->next == tmp)
	tmp_list->next = tmp->next;
      tmp_list = tmp_list->next;
    }
  return (EXIT_SUCCESS);
}
