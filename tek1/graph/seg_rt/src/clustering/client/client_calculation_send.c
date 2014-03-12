/*
** client_calculation_send.c for client in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May  6 12:56:27 2012 ronan guiho
** Last update Mon May  7 19:03:17 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

SOCKET	csock;
pthread_mutex_t mutex;

int	client_calculation_send(char *buffer, int x, int y)
{
  char	*trame;
  char	*header;

  if ((header = client_calculation_header(x, 0, y)) == NULL)
    return (EXIT_FAILURE);
  //  printf("[*] Raytracer: Clustering: Send [%d COLUMN] to [SERVER].\n", x);
  trame = my_strconcat(header, buffer);
  trame = client_endtrame(trame);
  pthread_mutex_lock(&mutex);
  if ((send(csock, trame, my_strlen(trame), 0)) <= 0)
    return (EXIT_FAILURE);
  pthread_mutex_unlock(&mutex);
  free(trame);
  free(header);
  return (EXIT_SUCCESS);
}
