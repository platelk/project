/*
** data.c for data in /home/platel_k/projet/sys_unix/myselect/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Jan 11 20:28:09 2012 kevin platel
** Last update Sun Feb 12 18:23:09 2012 kevin platel
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

int	get_number(void)
{
  int	nbr;
  char	buffer[11];
  int	len;

  echo_mode(SET);
  raw_mode(UNSET);
  my_printf("\ngive number : ");
  if ((len = read(0, buffer, 10)) < 0)
    return (ERROR);
  buffer[len] = 0;
  nbr = my_getnbr(buffer);
  return (nbr);
}

int	treatment_of_data(int action, t_element **list)
{
  t_element	*tmp;
  t_element	*tmp2;

  tmp = (*list);
  while ((*list) != NULL && (*list)->cursor != 1 && (*list) != (*list)->next)
    (*list) = (*list)->next;
  if (action == UP || action == DOWN || action == SELECT)
    (*list)->cursor = 0;
  if (action == UP || action == DOWN)
    action == UP ? ((*list)->prev->cursor = 1) : ((*list)->next->cursor = 1);
  else if (action == SELECT)
    {
      tmp2 = (*list);
      if (alum_remove(list, get_number()) == END)
	return (END);
    }
  (tmp2 == tmp) && (tmp2 != (*list)) ? ((*list) = (*list)) : ((*list) = tmp);
  return (action);
}

int	return_data(t_element *list)
{
  t_element *tmp2;
  t_element *tmp;
  int	i;

  tmp2 = list;
  if (list != NULL)
    tmp = list->prev;
  i = 0;
  while (list != NULL && list != tmp)
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

int	alum_remove(t_element **list, int nbr)
{
  int	i;

  echo_mode(UNSET);
  raw_mode(SET);
  if (nbr <= 0)
    nbr = 1;
  i = 0;
  while ((*list)->name[i])
    i++;
  nbr = i - nbr;
  while (i > nbr && i > 0)
    i--;
  if (i >= 0)
    (*list)->name[i] = '\0';
  (*list)->cursor = 1;
  if ((nbr < 0) || (my_is_instr('|', (*list)->name) == IS_NOT_STR))
    {
      (*list) = del_one_in_list((*list));
      if ((*list) == NULL)
	return (END);
      (*list)->cursor = 1;
    }
  return (0);
}
