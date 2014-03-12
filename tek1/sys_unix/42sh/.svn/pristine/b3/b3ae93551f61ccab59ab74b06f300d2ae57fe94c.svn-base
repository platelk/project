/*
** edit_history.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Apr 24 11:31:32 2012 alexis leprovost
** Last update Sat May 19 11:09:51 2012 alexis leprovost
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
edit_uphistory(t_global *global, t_line **line, char *prompt, char *buff)
{
  buff = buff;
  prompt = prompt;
  if (global->hist)
    {
      if (termcap_action(1, CD_MOVE_STRING, NULL, 0) ||
	  termcap_delete(edit_cp(*line), LEFT_MOVE_STRING, global, -1))
	return (EXIT_FAILURE);
      edit_freelist(*line);
      *line = edit_convertstr(global->hist->command);
      if (global->hist->prev)
	global->hist = global->hist->prev;
      ultim_func(*line, global);
    }
  return (EXIT_SUCCESS);
}

int
edit_downhistory(t_global *global, t_line **line, char *prompt, char *buff)
{
  buff = buff;
  prompt = prompt;
  if (global->hist)
    {
      if (termcap_action(1, CD_MOVE_STRING, NULL, 0) ||
	  termcap_delete(edit_cp(*line), LEFT_MOVE_STRING, global, -1))
	return (EXIT_FAILURE);
      (*line) ? edit_freelist(*line) : (*line = NULL);
      if (global->hist && global->hist->next)
	{
	  global->hist = global->hist->next;
	  *line = edit_convertstr(global->hist->command);
	}
      else
	*line = NULL;
      ultim_func(*line, global);
    }
  return (EXIT_SUCCESS);
}
