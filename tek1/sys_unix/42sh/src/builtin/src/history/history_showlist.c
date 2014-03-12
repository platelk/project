/*
** history_showlist.c for history in /home/vink/projet/sys_unix/42sh/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Thu May 17 17:58:08 2012 kevin platel
** Last update Thu May 17 17:58:09 2012 kevin platel
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#include	"t_history.h"

int	put_error(char *cmd, int flag)
{
  int	i;

  i = -1;
  if (cmd)
    while (cmd[++i])
      if (strchr("0123456789", cmd[i]) == NULL)
	{
	  if (flag)
	    fprintf(stderr, "history: Badly formed number.\n");
	  return (EXIT_FAILURE);
	}
  return (EXIT_SUCCESS);
}

t_history	*advance_history(t_history *history, char *str)
{
  int	i;

  i = -1;
  if (str)
    {
      if (!put_error(str, 0))
	while (history && history->prev && ++i < atoi(str) -1)
	  history = history->prev;
    }
  else
    while (history && history->prev != NULL)
      history = history->prev;
  return (history);
}

void	show_param_history(t_history *list)
{
  printf("\t%d\t", list->id_cmd);
  printf("%s\t", list->time);
  printf("%s\n", list->command);
}

void	show_history(t_history *list, char *nb)
{
  int	i;

  i = 0;
  list = advance_history(list, nb);
  if (nb == NULL)
    while (list != NULL)
      {
	show_param_history(list);
	list = list->next;
      }
  else
    while (list && i < atoi(nb))
      {
	show_param_history(list);
	list = list->next;
	i++;
      }
}
