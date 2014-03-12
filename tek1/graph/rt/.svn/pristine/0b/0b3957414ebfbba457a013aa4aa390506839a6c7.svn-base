/*
** server_client_display.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  2 14:14:47 2012 ronan guiho
** Last update Sun Jun  3 08:32:50 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>

#include "client.h"

void		server_client_display(t_client *list)
{
  t_client	*tmp;

  tmp = list;
  my_printf("====- LIST CLIENT -====\n");
  while (tmp)
    {
      my_printf("[%d] [%s:%d] [%d ms] [%d core] [%s]\n", \
	     tmp->id, inet_ntoa(tmp->csin->sin_addr),
	     htons(tmp->csin->sin_port), tmp->latence,
	     tmp->core, (tmp->status == 0) ? "Waiting" : "Process");
      tmp = tmp->next;
    }
  my_printf("=======================\n");
}
