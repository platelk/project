/*
** edit_history.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Tue Apr 24 11:31:32 2012 alexis leprovost
** Last update Sat Apr 28 14:32:15 2012 alexis leprovost
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
  if (termcap_action(1, CONTROL_STRING) ||
      termcap_delete(global->curser, LEFT_MOVE_STRING))
    return (EXIT_FAILURE);
  global->curser = 0;
  if (global->hist)
    {
      edit_freelist(*line);
      *line = edit_convertstr(global->hist->command);
      if (global->hist->prev)
	global->hist = global->hist->prev;
    }
  global->curser = edit_listlen(*line);
  edit_afflist(*line);
  return (EXIT_SUCCESS);
}

int
edit_downhistory(t_global *global, t_line **line, char *prompt, char *buff)
{
  buff = buff;
  prompt = prompt;
  if (termcap_action(1, CONTROL_STRING) ||
      termcap_delete(global->curser, LEFT_MOVE_STRING))
    return (EXIT_FAILURE);
  global->curser = 0;
  if (global->hist)
    {
      edit_freelist(*line);
      if (global->hist && global->hist->next)
	{
	  global->hist = global->hist->next;
	  *line = edit_convertstr(global->hist->command);
	}
      else
	*line = NULL;
    }
  global->curser = edit_listlen(*line);
  edit_afflist(*line);
  return (EXIT_SUCCESS);
}
