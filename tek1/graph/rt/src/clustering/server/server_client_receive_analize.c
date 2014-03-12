/*
** server_client_receive_analize.c for server in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May  6 19:38:46 2012 ronan guiho
** Last update Mon May  7 15:40:28 2012 ronan guiho
*/

#include <stdlib.h>

#include "server.h"

int		server_client_add_trame(t_trame **list, int size, \
					char *buffer)
{
  t_trame	*ptr;
  t_trame	*tmp;

  tmp = *list;
  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    return (EXIT_FAILURE);
  ptr->size = size;
  ptr->buffer = my_strdup(buffer);
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

int	server_client_receive_analize(t_trame **list_trame, \
				      char *buffer)
{
  int	i;
  char	**tab;

  i = 0;
  if ((tab = my_strtok(buffer, " ", 0)) == NULL)
    return (EXIT_FAILURE);
  while (tab[i])
    {
      if (is_number(tab[i]) == 1)
	{
	  if ((server_client_add_trame(list_trame, my_getnbr(tab[i]),
				       tab[i + 1])) == EXIT_FAILURE)
	    return (EXIT_FAILURE);
	  i++;
	}
      else
	(*list_trame)->buffer = my_strconcat((*list_trame)->buffer, tab[i]);
      if (tab[i] != NULL)
	i++;
    }
  return (EXIT_SUCCESS);
}
