/*
** server_management.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May  4 14:02:49 2012 ronan guiho
** Last update Fri May 25 10:52:26 2012 ronan guiho
*/

#include <stdlib.h>
#include <unistd.h>

#include "server.h"

t_client	*list;

void	       *server_management(void *tmp)
{
  int		rtrn;
  char		buffer[1024];
  int		flag_start;

  (void)tmp;
  flag_start = 0;
  while (42)
    {
      if ((rtrn = read(0, buffer, 1024)) < 0)
	return (NULL);
      buffer[rtrn - 1] = '\0';
      if ((my_strcmp(buffer, "/start") == 0) && (flag_start == 0))
	{
	  if (server_client_count() >= 1)
	    {
	      printf("[*] Raytracer: Clustering: Start of the distribution computing.\n");
	      if ((server_distribution_start()) == EXIT_FAILURE)
		return (NULL);
	      flag_start = 1;
	    }
	  else
	    printf("Raytracer: Clustering: Error: Start not avaible, 0 client.\n");
	}
      else if ((my_strcmp(buffer, "/start") == 0) && (flag_start == 1))
	printf("Raytracer: Clustering: Error: Start not available, already in progress.\n");
      else if (my_strcmp(buffer, "/list") == 0)
	server_client_display(list);
      else if (my_strcmp(buffer, "/quit") == 0)
	server_close(0);
      else
	printf("Raytracer: Clustering: Error: Command unknow.\n");
    }
  return (NULL);
}

int		server_management_start()
{
  pthread_t	thread_management;

  printf("[*] Raytracer: Clustering: Start MANAGEMENT service ...");
  if (pthread_create(&thread_management, NULL, server_management, NULL) < 0)
    {
      printf("Raytracer: Clustering: Error: Failed to start MANAGEMENT service.\n");
      return (EXIT_FAILURE);
    }
  printf(" \033[32mDone !\033[00m\n");
  return (EXIT_SUCCESS);
}
