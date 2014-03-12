/*
** server_distribution_plage_calcul.c for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri May  4 15:18:24 2012 ronan guiho
** Last update Fri Jun  1 11:03:26 2012 ronan guiho
*/

#include <stdlib.h>

#include "global.h"
#include "server.h"

t_client	*client;
t_global	*global_thread;

int		server_distribution_plage_calcul_a(t_plage **list, \
						   int start_x, int end_x, \
						   int end_y)
{
  t_plage	*ptr;
  t_plage	*tmp;

  tmp = *list;
  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    return (EXIT_FAILURE);
  ptr->X_start = start_x;
  ptr->X_end = end_x;
  ptr->Y_start = 0;
  ptr->Y_end = end_y;
  ptr->next = NULL;
  if (*list == NULL)
    *list = ptr;
  else
    {
      while (tmp->next)
	tmp = tmp->next;
      tmp->next = ptr;
    }
  return (EXIT_SUCCESS);
}

t_plage		*server_distribution_plage_calcul()
{
  int		i;
  t_plage	*list;
  int		count_client;
  int		atribution_client[2];
  t_plage	*tmp;

  i = 0;
  list = NULL;
  count_client = server_client_count();
  atribution_client[0] = global_thread->window->x_win / count_client;
  atribution_client[1] = global_thread->window->x_win % count_client;
  while ((i + atribution_client[1]) < global_thread->window->x_win)
    {
      if ((server_distribution_plage_calcul_a(&list, i, \
					      i + atribution_client[0], \
					      global_thread->window->y_win)) \
	  == EXIT_FAILURE)
	return (NULL);
      i = i + atribution_client[0];
    }
  tmp = list;
  while (tmp->next)
    tmp = tmp->next;
  tmp->X_end = tmp->X_end + atribution_client[1];
  return (list);
}
