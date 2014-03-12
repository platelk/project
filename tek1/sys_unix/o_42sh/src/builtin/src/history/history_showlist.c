/*
** history_showlist.c for 42sh in /home/phalip_z//exos/projets/42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Thu Apr 19 00:48:19 2012 zoe phalippou
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"t_history.h"

int	put_error(char *cmd)
{
  int	i;

  i = -1;
  if (cmd)
    while (cmd[++i])
      if (strchr("0123456789", cmd[i]) == NULL)
	{
	  fprintf(stderr, "history: Badly formed number.\n");
	  return (EXIT_FAILURE);
	}
  return (EXIT_SUCCESS);
}

void	show_param_history(t_history *list)
{
  printf("%d\t", list->id_cmd);
  printf("%s\t", list->time);
  printf("%s\n", list->command);
}

void	show_history(t_history *list, int nb)
{
  int	i;

  i = 0;
  while (list && list->prev != NULL)
    list = list->prev;
  if (nb == -1)
    while (list != NULL)
      {
	show_param_history(list);
	list = list->next;
      }
  else
    while (list && i < nb)
      {
	show_param_history(list);
	list = list->next;
	i++;
      }
}
