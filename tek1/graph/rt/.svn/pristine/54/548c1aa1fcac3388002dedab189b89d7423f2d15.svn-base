/*
** client_listen.c for client in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  2 18:58:56 2012 ronan guiho
** Last update Sun Jun  3 08:37:39 2012 ronan guiho
*/

#include <stdlib.h>
#include <unistd.h>

#include "my.h"
#include "global.h"
#include "client.h"

SOCKET		csock;
pthread_mutex_t mutex;

t_global	*global_thread;

int		client_listen_treatement_plage(char *buffer)
{
  char		**tab;
  t_plage	*plage;
  pthread_t	thread_plage;

  if ((plage = malloc(sizeof(*plage))) == NULL)
    return (EXIT_FAILURE);
  if ((tab = my_strtok(buffer, "-", 0)) == NULL)
    return (EXIT_FAILURE);
  my_printf("[*] Raytracer: Clustering: Receive plage [%s:%s].\n", \
	 tab[0], tab[1]);
  plage->X_start = my_getnbr(tab[0]);
  plage->X_end = my_getnbr(tab[1]);
  if (plage->X_start > global_thread->window->x_win ||	\
      plage->X_end > global_thread->window->x_win)
    return (EXIT_FAILURE);
  if ((pthread_create(&thread_plage, NULL, client_calculation, plage)) < 0)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		client_listen_treatement(char *buffer)
{
  char		*pong;

  if (my_strcmp(buffer, "PING") == 0)
    {
      pong = client_endtrame("PONG");
      pthread_mutex_lock(&mutex);
      if ((send(csock, pong, my_strlen(pong), 0)) <= 0)
	{
	  my_printf("Raytracer: Clustering: Error: Server disconnect.\n");
	  return (EXIT_FAILURE);
	}
      pthread_mutex_unlock(&mutex);
    }
  else
    if ((client_listen_treatement_plage(buffer)) == EXIT_FAILURE)
      return (EXIT_SUCCESS);
  return (EXIT_SUCCESS);
}

int		client_listen()
{
  int		retrn;
  char		buffer[1024];

  while (42)
    {
      if ((retrn = recv(csock, buffer, 1024, 0)) <= 0)
	{
	  my_printf("Raytracer: Clustering: Error: Server disconnect.\n");
	  return (EXIT_FAILURE);
	}
      buffer[retrn] = '\0';
      if ((client_listen_treatement(buffer)) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
