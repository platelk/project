/*
** edit_swap.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Apr 27 17:35:24 2012 alexis leprovost
** Last update Sat May 19 11:52:28 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"global.h"
#include	"edit.h"
#include	"xsys.h"
#include	"t_history.h"
#include	"get_next_line.h"
#include	"my.h"

int
edit_swap(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;
  char	data;

  prompt = prompt;
  buff = buff;
  global = global;
  tmp = *line;
  while (tmp && !tmp->status)
    tmp = tmp->next;
  if (!tmp || (tmp && !tmp->prev))
    return (EXIT_FAILURE);
  else
    {
      data = tmp->letter;
      tmp->letter = tmp->prev->letter;
      tmp->prev->letter = data;
    }
  termcap_delete(2, LEFT_MOVE_STRING, NULL, 0);
  termcap_action(1, INSERT_ON, NULL, 0);
  write(1, &tmp->prev->letter, 1);
  write(1, &tmp->letter, 1);
  termcap_action(1, INSERT_OFF, NULL, 0);
  return (EXIT_SUCCESS);
}
