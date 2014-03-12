/*
** client_close.c for client in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  2 18:42:54 2012 ronan guiho
** Last update Fri May  4 16:14:42 2012 ronan guiho
*/

#include <stdlib.h>
#include <unistd.h>

#include "client.h"

SOCKET		csock;

void	client_close(int seg)
{
  (void)seg;
  close(csock);
  exit(EXIT_FAILURE);
}
