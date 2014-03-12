/*
** edit_move.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Apr 27 15:28:20 2012 alexis leprovost
** Last update Sat Apr 28 17:49:03 2012 alexis leprovost
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
edit_leftmove(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;

  prompt = prompt;
  buff = buff;
  tmp = *line;
  while (tmp && !tmp->status)
    tmp = tmp->next;
  if (global->curser > 0)
    {
      if (termcap_action(1, LEFT_MOVE_STRING))
	return (EXIT_FAILURE);
      --global->curser;
      if (tmp)
	tmp->status = 0;
      if (tmp && tmp->prev)
	tmp->prev->status = 1;
    }
  return (EXIT_SUCCESS);
}

int
edit_rightmove(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;

  prompt = prompt;
  buff = buff;
  tmp = *line;
  while (tmp && !tmp->status)
    tmp = tmp->next;
  if (global->curser < edit_listlen(*line))
    {
      if (termcap_action(1, RIGHT_MOVE_STRING))
	return (EXIT_SUCCESS);
      ++global->curser;
      if (!tmp)
	(*line)->status = 1;
      if (tmp && tmp->next)
	{
	  tmp->status = 0;
	  tmp->next->status = 1;
	}
    }
  return (EXIT_SUCCESS);
}

int
edit_switchmove(t_global *global, t_line **line, char *prompt, char *buff)
{
  buff = buff;
  if (global->curser > 0)
    edit_control(global, line, prompt, START_EDIT_STRING);
  else
    edit_control(global, line, prompt, END_EDIT_STRING);
  return (EXIT_SUCCESS);
}

int
edit_goto_nextspace(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;

  prompt = prompt;
  buff = buff;
  if (*line == NULL || edit_listlen(*line) == global->curser)
    return (EXIT_SUCCESS);
  tmp = *line;
  while (tmp && !tmp->status)
    tmp = tmp->next;
  if (tmp == NULL)
    {
      tmp = *line;
      ++global->curser;
      termcap_action(1, RIGHT_MOVE_STRING);
    }
  while (tmp->next && (tmp->letter != ' ' || tmp->status))
    {
      tmp->status = 0;
      ++global->curser;
      termcap_action(1, RIGHT_MOVE_STRING);
      tmp = tmp->next;
    }
  tmp->status = 1;
  return (EXIT_SUCCESS);
}

int
edit_goto_prevspace(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;

  prompt = prompt;
  buff = buff;
  tmp = *line;
  while (tmp && !tmp->status)
    tmp = tmp->next;
  if (tmp == NULL)
    return (EXIT_SUCCESS);
  while (tmp && (tmp->letter != ' '  || tmp->status))
    {
      tmp->status = 0;
      --global->curser;
      termcap_action(1, LEFT_MOVE_STRING);
      tmp = tmp->prev;
    }
  if (tmp)
    tmp->status = 1;
  return (EXIT_SUCCESS);
}
