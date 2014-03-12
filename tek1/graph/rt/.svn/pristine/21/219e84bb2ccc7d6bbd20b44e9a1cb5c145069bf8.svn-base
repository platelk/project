/*
** server_distribution.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May  4 15:11:26 2012 ronan guiho
** Last update Sun Jun  3 08:34:38 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

void		*server_distribution(void *vd)
{
  t_plage	*list_plage;

  (void)vd;
  if ((list_plage = server_distribution_plage_calcul()) == NULL)
    return (NULL);
  if ((server_distribution_atribution(list_plage)) == EXIT_FAILURE)
    return (NULL);
  if ((server_distribution_send()) == EXIT_FAILURE)
    return (NULL);
  return (NULL);
}

int		server_distribution_start()
{
  pthread_t	thread_distribution;

  if (pthread_create(&thread_distribution, NULL, \
		     server_distribution, NULL) < 0)
    {
      my_printf("Raytracer: Clustering: Error: Failed to start service.\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
