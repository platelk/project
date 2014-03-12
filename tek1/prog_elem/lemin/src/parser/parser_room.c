/*
** parser_room.c for lemin in /home/guiho_r/tek1/lemin/src/parser
**
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
**
** Started on  Wed Apr  4 15:19:39 2012 ronan guiho
** Last update Fri Apr 20 17:26:11 2012 matthieu przybylski
*/

#include <stdlib.h>

#include "lemin.h"

int		parser_error_room_suite(char **tab_room, int nb_element, int i)
{
  int		error;

  error = 0;
  if (nb_element >= 3)
    {
      if (my_getnbr(tab_room[1]) < 0 || my_getnbr(tab_room[2]) < 0)
	{
	  my_printf("lemin: error(%d): position can't be negative\n", i + 1);
	  error = 1;
	}
    }
  return (error);
}
int		parser_error_room(char **tab_room, int i)
{
  int		error;
  int		nb_element;

  error = 0;
  nb_element = parser_size_tab(tab_room);
  if (nb_element < 3)
    {
      my_printf("lemin: error(%d): missing information link's at room\n",
		i + 1);
      error = 1;
    }
  else if (nb_element > 3)
    {
      my_printf("lemin: error(%d): too more information link's at room\n",
		i + 1);
      error = 1;
    }
  error = parser_error_room_suite(tab_room, nb_element, i);
  if (error == 1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int		parser_create_room(t_room **list, char **tab, int state)
{
  t_room	*ptr;
  t_room	*tmp;

  tmp = *list;
  if ((ptr = malloc(sizeof(*ptr))) == NULL)
    return (EXIT_FAILURE);
  ptr->occ = ((state == START) ? 1 : 0);
  ptr->name = my_strdup(tab[0]);
  ptr->pos[0] = my_getnbr(tab[1]);
  ptr->pos[1] = my_getnbr(tab[2]);
  ptr->status = state;
  ptr->weight = -1;
  ptr->link = NULL;
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

int		parser_room_suite(t_glob *global, char **tab_parser, int i,
				  int state)
{
  char		delim[2];
  char		**tab_room;

  delim[0] = DELIM_ROOM;
  delim[1] = '\0';
  if (state != TMP)
    i++;
  if ((tab_room = my_strtok(tab_parser[i], delim, TOK_DELIM)) == NULL)
    return (-1);
  if ((parser_error_room(tab_room, i)) == EXIT_FAILURE)
    return (-1);
  if ((parser_create_room(&global->room, tab_room, state)) == EXIT_FAILURE)
    return (-1);
  parser_free_tab(tab_room);
  return (i);
}
int		parser_room(t_glob *global, char **tab_parser,
			    int indice)
{
  int		i;
  int		state;

  i = indice;
  global->room = NULL;
  state = TMP;
  while (parser_check_if_link(tab_parser[i]) == 0)
    {
      while ((tab_parser[i][0] == '#' && tab_parser[i][1] != '#') ||
	     (tab_parser[i][0] == '\n'))
	i++;
      if (parser_check_if_link(tab_parser[i]) == 1)
	return (i);
      if ((state = parser_check_if_state(tab_parser[i], i)) == -1)
	return (-1);
      if ((i = parser_room_suite(global, tab_parser, i, state)) == -1)
	return (-1);
      i++;
    }
  return (i);
}
