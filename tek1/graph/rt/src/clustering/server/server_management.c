/*
** server_management.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May  4 14:02:49 2012 ronan guiho
** Last update Sun Jun  3 19:43:36 2012 alexis leprovost
*/

#include <stdlib.h>
#include <unistd.h>

#include "server.h"

t_client	*list;
t_global	*global_thread;

int	       server_management_cmp(char *buffer, int flag_start)
{
  if ((my_strcmp(buffer, "/start") == 0) && (flag_start == 0))
    {
      if (server_client_count() >= 1)
	{
	  my_printf("[*] Raytracer: Clustering: Start of the distribution.\n");
	  if ((server_distribution_start()) == EXIT_FAILURE)
	    return (-1);
	  flag_start = 1;
	}
      else
	my_printf("Raytracer: Clustering: Error: Start not avaible\n");
    }
  else if ((my_strcmp(buffer, "/start") == 0) && (flag_start == 1))
    my_printf("Raytracer: Clustering: Error: Already in progress.\n");
  else if (my_strcmp(buffer, "/list") == 0)
    server_client_display(list);
  else if (my_strcmp(buffer, "/quit") == 0)
    server_close(0);
  else
    my_printf("Raytracer: Clustering: Error: Command unknow.\n");
  return (flag_start);
}

int		server_management_n(t_normal_info *normal_info)
{
  sleep(normal_info->wait);
  if (server_client_count() >= 1)
    {
      if ((server_distribution_start()) == EXIT_FAILURE)
	return (EXIT_FAILURE);
    }
  else
    my_printf("[*] Raytracer: Clustering: Error: Too`many client.\n");
  return (EXIT_SUCCESS);
}

void		*server_management(void *tmp)
{
  int		rtrn;
  char		buffer[1024];
  int		flag_start;
  t_normal_info	*normal_info;

  (void)tmp;
  flag_start = 0;
  normal_info = (t_normal_info *)global_thread->info.arg;
  if (normal_info->wait == 0)
    while (42)
      {
	if ((rtrn = read(0, buffer, 1024)) >= 1)
	  {
	    buffer[rtrn - 1] = '\0';
	    if ((flag_start = server_management_cmp(buffer, flag_start)) == -1)
	      return (NULL);
	  }
      }
  else
    server_management_n(normal_info);
  return (NULL);
}

int		server_management_start()
{
  pthread_t	thread_management;

  my_printf("[*] Raytracer: Clustering: Start MANAGEMENT service ...");
  if (pthread_create(&thread_management, NULL, server_management, NULL) < 0)
    {
      my_printf("Raytracer: Clustering: Error: Failed to start service.\n");
      return (EXIT_FAILURE);
    }
  my_printf(" \033[32mDone !\033[00m\n");
  return (EXIT_SUCCESS);
}
