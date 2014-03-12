/*
** put_history.c for 42sh in /home/phalip_z//exos/projets/42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Mon Apr  9 16:04:14 2012 zoe phalippou
** Last update Sat May 19 15:35:10 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

#include	"my.h"
#include	"xsys.h"
#include	"history_create_list.h"
#include	"t_history.h"

void	history_fill(int id_command, char *cmd,
			     t_history *element, t_history **list)
{
  element->id_cmd = id_command;
  element->command = my_strdup(cmd);
  if (cmd)
    free(cmd);
  element->next = NULL;
  element->prev = *list;
}

  int	history_putlist(char *cmd, t_history **list, t_config *config)
{
  t_history	*element;
  int		id_command;

  id_command = 0;
  if (list && (*list) && (*list)->prev)
    id_command = (*list)->id_cmd + 1;
  if (!(*list) || my_strcmp((*list)->command, cmd))
    {
      if ((element = xmalloc(sizeof(*element))) == NULL)
	return (EXIT_FAILURE);
      history_fill(id_command, cmd, element, list);
      if (*list)
	(*list)->next = element;
      *list = element;
    }
  else
    (*list)->id_cmd += 1;
  if (list && (*list) && (*list)->time)
    free((*list)->time);
  (*list)->time = xtime();
  id_command++;
  if (history_list_config(config, *list, 1) == NULL)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
