/*
** put_history.c for 42sh in /home/phalip_z//exos/projets/42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Mon Apr  9 16:04:14 2012 zoe phalippou
** Last update Wed Apr 25 09:55:24 2012 kevin platel
*/

#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"xsys.h"
#include	"t_history.h"

int	history_putlist(char *cmd, t_history **list)
{
  t_history	*element;
  static int	id_command;

  if (!(*list) || my_strcmp((*list)->command, cmd))
    {
      if ((element = xmalloc(sizeof(*element))) == NULL)
	return (EXIT_FAILURE);
      element->id_cmd = id_command;
      element->command = my_strdup(cmd);
      element->next = NULL;
      element->prev = *list;
      if (*list)
	(*list)->next = element;
      *list = element;
    }
  else
      (*list)->id_cmd += 1;
  if ((*list)->time)
    free((*list)->time);
  (*list)->time = xtime();
  id_command++;
  return (EXIT_SUCCESS);
}
