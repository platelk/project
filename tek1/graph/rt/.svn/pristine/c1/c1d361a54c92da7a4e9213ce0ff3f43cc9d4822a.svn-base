/*
** server_ping.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed May  2 17:04:14 2012 ronan guiho
** Last update Sun Jun  3 17:01:45 2012 ronan guiho
*/

#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/time.h>

#include "client.h"
#include "server.h"

t_client		*list;

int			server_ping_send()
{
  t_client		*tmp;

  tmp = list;
  while (tmp)
    {
      if ((send(tmp->sock, "PING", my_strlen("PING"), 0)) <= 0)
	{
	  my_printf("Raytracer: Clustering: Error: PING failed to %s:%d\n", \
		 inet_ntoa(tmp->csin->sin_addr), \
		 htons(tmp->csin->sin_port));
	}
      gettimeofday(&tmp->tv, NULL);
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

void			*server_ping(void *tmp)
{
  struct timeval	tv1;
  struct timeval	tv2;
  long long		temps;

  (void)tmp;
  while (42)
    {
      server_ping_raz();
      server_ping_send();
      gettimeofday(&tv1, NULL);
      gettimeofday(&tv2, NULL);
      temps = tv2.tv_sec - tv1.tv_sec;
      while (temps < DELAY_PING)
	{
	  gettimeofday(&tv2, NULL);
	  temps = tv2.tv_sec - tv1.tv_sec;
	  usleep(1);
	}
      server_ping_check_recv();
    }
  return (NULL);
}

int			server_ping_start()
{
  pthread_t		thread_ping;

  my_printf("[*] Raytracer: Clustering: Start PING service ...");
  if (pthread_create(&thread_ping, NULL, server_ping, NULL) < 0)
    {
      my_printf("Raytracer: Clustering: Error: Failed PING service.\n");
      return (EXIT_FAILURE);
    }
  my_printf(" \033[32mDone !\033[00m\n");
  return (EXIT_SUCCESS);
}
