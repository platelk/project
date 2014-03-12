/*
** edit_store.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Apr 27 17:41:38 2012 alexis leprovost
** Last update Sat Apr 28 14:51:04 2012 alexis leprovost
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
  if (termcap_action(1, CONTROL_STRING) ||
      termcap_delete(global->curser, LEFT_MOVE_STRING))
    return (EXIT_FAILURE);
  global->curser = 0;
  str = edit_convertlist(*line);
  edit_freelist(global->data);
  global->data = edit_convertstr(str);
  (str) ? (free(str)) : (str = NULL);
  edit_freelist(*line);
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
  if (termcap_action(1, CONTROL_STRING) || !buff || !prompt)
    return (EXIT_FAILURE);
  edit_freelist(global->data);
  if (*line == NULL)
    {
      str = edit_convertlist(data);
      edit_freelist(data);
      data = NULL;
    }
  else
    {
      str = edit_convertlist((*line)->next);
      edit_freelist((*line)->next);
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
  edit_freelist(global->data);
  if (termcap_delete(global->curser, LEFT_MOVE_STRING))
    return (EXIT_FAILURE);
  global->curser = 0;
  while (*line && !(*line)->status)
    *line = (*line)->next;
  if (*line == NULL)
    data = NULL;
  else
    *line = (*line)->next;
  if (*line)
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
  t_line	*tmp;
  char	*str;

  prompt = prompt;
  buff = buff;
  tmp = *line;
  if (termcap_action(edit_listlen(global->data), RIGHT_MOVE_STRING))
    return (EXIT_FAILURE);
  str = edit_convertlist(global->data);
  data = edit_convertstr(str);
  *line = edit_concatlist(*line, data, global->curser);
  global->curser += edit_listlen(global->data);
  (str) ? (free(str)) : (str = NULL);
  return (EXIT_SUCCESS);
}
