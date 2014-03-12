/*
** edit_swap.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Apr 27 17:35:24 2012 alexis leprovost
** Last update Fri Apr 27 17:38:59 2012 alexis leprovost
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
  if (!tmp || (tmp && !tmp->next))
    return (EXIT_SUCCESS);
  else
    {
      data = tmp->letter;
      tmp->letter = tmp->next->letter;
      tmp->next->letter = data;
    }
  return (EXIT_SUCCESS);
}
