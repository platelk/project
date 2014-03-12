/*
** server_distribution_atribution.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sat May  5 19:36:02 2012 ronan guiho
** Last update Fri Jun  1 11:02:07 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

t_client	*list;

t_plage		*server_distribution_atribution_plage(t_plage *plage)
{
  t_plage	*ptr;

  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    return (NULL);
  ptr->X_start = plage->X_start;
  ptr->X_end = plage->X_end;
  ptr->Y_start = plage->Y_start;
  ptr->Y_end = plage->Y_end;
  ptr->next = NULL;
  return (ptr);
}

int		server_distribution_atribution(t_plage *plage)
{
  t_client	*tmp_client;
  t_plage	*tmp_plage;
  t_plage	*plage_cpy;

  tmp_client = list;
  tmp_plage = plage;
  while (tmp_client)
    {
      if ((plage_cpy = server_distribution_atribution_plage(tmp_plage)) \
	  == NULL)
	return (EXIT_FAILURE);
      tmp_client->plage = plage_cpy;
      tmp_client = tmp_client->next;
      tmp_plage = tmp_plage->next;
    }
  return (EXIT_SUCCESS);
}
