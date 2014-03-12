/*
** server_client_receive_is_valide.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Mon May  7 17:07:39 2012 ronan guiho
** Last update Mon May  7 17:12:40 2012 ronan guiho
*/
#include <stdlib.h>

#include "server.h"

int	server_client_receive_is_valide(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] == 4)
	return (i);
      i++;
    }
  return (-1);
}
