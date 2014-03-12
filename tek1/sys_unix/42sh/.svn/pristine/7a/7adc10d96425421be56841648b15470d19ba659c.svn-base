/*
** edit_store.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Apr 27 17:41:38 2012 alexis leprovost
** Last update Sat May 19 11:47:32 2012 alexis leprovost
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
edit_allstore(t_global *global, t_line **line, char *prompt, char *buff)
{
  char	*str;

  prompt = prompt;
  buff = buff;
  if (termcap_action(1, CD_MOVE_STRING, NULL, 0) ||
      termcap_delete(edit_cp(*line), LEFT_MOVE_STRING, global, -1))
    return (EXIT_FAILURE);
  global->curser[X] = 0;
  str = edit_convertlist(*line);
  (global->data) ? edit_freelist(global->data) : (global->data = NULL);
  global->data = edit_convertstr(str);
  (str) ? (free(str)) : (str = NULL);
  (*line) ? edit_freelist(*line) : (*line = NULL);
  *line = NULL;
  return (EXIT_SUCCESS);
}

int
edit_rightstore(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*data;
  char	*str;

  data = *line;
  while (*line && !(*line)->status)
    *line = (*line)->next;
  if (termcap_action(1, CD_MOVE_STRING, NULL, 0) || !buff || !prompt)
    return (EXIT_FAILURE);
  (global->data) ? edit_freelist(global->data) : (global->data = NULL);
  if (*line == NULL)
    {
      str = edit_convertlist(data);
      (data) ? edit_freelist(data) : (data = NULL);
      data = NULL;
    }
  else
    {
      str = edit_convertlist((*line)->next);
      ((*line)->next) ? edit_freelist((*line)->next) : ((*line)->next = NULL);
      (*line)->next = NULL;
    }
  global->data = edit_convertstr(str);
  (str) ? (free(str)) : (str = NULL);
  *line = data;
  return (EXIT_SUCCESS);
}

int
edit_leftstore(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*data;
  char	*str;

  prompt = prompt;
  buff = buff;
  data = *line;
  (global->data) ? edit_freelist(global->data) : (global->data = NULL);
  if (termcap_delete(edit_cp(*line), LEFT_MOVE_STRING, global, -1))
    return (EXIT_FAILURE);
  while (*line && !(*line)->status)
    *line = (*line)->next;
  if (*line == NULL)
    data = NULL;
  else
    *line = (*line)->next;
  if (*line && (*line)->prev)
    {
      (*line)->prev->next = NULL;
      (*line)->prev = NULL;
    }
  str = edit_convertlist(data);
  global->data = edit_convertstr(str);
  (str) ? (free(str)) : (str = NULL);
  return (EXIT_SUCCESS);
}

int
edit_paste(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*data;
  char	*str;
  int	len;

  prompt = prompt;
  buff = buff;
  if ((edit_listlen(*line) + global->len) <
      MAX_LINE_NUMBER &&
      (edit_listlen(*line) + global->len) <
      ((global->dom[Y] - 1) * global->dom[X]))
    {
      len = edit_listlen(global->data);
      str = edit_convertlist(global->data);
      data = edit_convertstr(str);
      *line = edit_concatlist(*line, data, edit_cp(*line));
      termcap_action(len, RIGHT_MOVE_STRING, global, 1);
      termcap_display(*line, global);
      (str) ? (free(str)) : (str = NULL);
    }
  return (EXIT_SUCCESS);
}
