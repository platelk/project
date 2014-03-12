/*
** history_freelist.c for 42sh in /home/phalip_z//42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Wed May 16 18:06:44 2012 zoe phalippou
** Last update Fri May 18 18:08:05 2012 zoe phalippou
*/

#include	<stdlib.h>

#include	"t_history.h"

t_history	*free_history(t_history *history)
{
  t_history	*tmp;

  while (history)
    {
      tmp = history->prev;
      if (history->command)
	free(history->command);
      if (history->time)
	free(history->time);
      free(history);
      history = tmp;
    }
  history = NULL;
  return (history);
}

