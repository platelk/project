/*
** data.c for data in /home/platel_k/projet/sys_unix/myselect/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Jan 11 20:28:09 2012 kevin platel
** Last update Tue Jan 31 15:49:25 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "myselect.h"

int	get_data(t_term *term)
{
  char	buffer[4];

  buffer[0] = 0;
  buffer[1] = 0;
  if (read(term->fd, buffer, 4) < 0)
    return (ERROR);
  if (buffer[0] == QUIT)
    return (QUIT);
  else if (buffer[0] == ECHAP && buffer[1] == 0)
    return (ECHAP);
  else if (buffer[0] == SELECT)
    return (SELECT);
  else if (buffer[0] == DELETE)
    return (DELETE);
  else if (buffer[0] == 27)
    if (buffer[1] == 91)
      {
	if (buffer[2] == UP)
	  return (UP);
	else if (buffer[2] == DOWN)
	  return (DOWN);
      }
  return (0);
}

int	treatment_of_data(int action, t_element *list)
{
  while (list->cursor != 1)
    list = list->next;
  if (action == UP)
    {
      list->cursor = 0;
      list->prev->cursor = 1;
    }
  else if (action == DOWN)
    {
      list->cursor = 0;
      list->next->cursor = 1;
    }
  else if (action == SELECT)
    {
      list->is_select == 1 ? (list->is_select = 0) : (list->is_select = 1);
      list->cursor = 0;
      list->next->cursor = 1;
    }
  else if (action == DELETE)
    {
      list = del_one_in_list(list);
      list->cursor = 1;
    }
  return (action);
}

int	return_data(t_element *list)
{
  t_element *tmp2;
  t_element *tmp;
  int	i;

  tmp2 = list;
  tmp = list->prev;
  i = 0;
  while (list != tmp)
    {
      if (list->is_select == 1)
	{
	  write(1, " ", 1);
	  write(1, list->name, list->lenght);
	  i++;
	}
      list = list->next;
      if (list == tmp)
	tmp = tmp2;
    }
  return (0);
}
