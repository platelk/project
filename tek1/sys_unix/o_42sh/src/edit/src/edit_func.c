/*
** edit_func.c for 42sh in /home/leprov_a//depot/42sh/src/edit
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 25 11:13:16 2012 alexis leprovost
** Last update Sun Apr 29 13:28:23 2012 alexis leprovost
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
edit_delete(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;

  tmp = *line;
  prompt = prompt;
  buff = buff;
  while (tmp && !tmp->status)
    tmp = tmp->next;
  if (global->curser > 0 && tmp && !termcap_delete(1, LEFT_MOVE_STRING))
    {
      --global->curser;
      if (tmp->prev)
	{
	  tmp->prev->status = 1;
	  tmp->prev->next = tmp->next;
	}
      if (tmp->next)
	tmp->next->prev = tmp->prev;
      if (!tmp->prev && tmp->next)
	*line = tmp->next;
      if (!tmp->next && !tmp->prev)
	*line = NULL;
      free(tmp);
      tmp = NULL;
    }
  return (EXIT_SUCCESS);
}

int
edit_suppr(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;

  tmp = *line;
  prompt = prompt;
  buff = buff;
  while (tmp && !tmp->status)
    tmp = tmp->next;
  if (global->curser < edit_listlen(*line) &&
      !termcap_action(1, RIGHT_MOVE_STRING))
    {
      termcap_delete(1, LEFT_MOVE_STRING);
      if (!tmp && *line)
	{
	  tmp = *line;
	  *line = tmp->next;
	}
      else if (tmp && (tmp = tmp->next))
	{
	  tmp->prev->next = tmp->next;
	  if (tmp->next)
	    {
	      tmp->next->status = 1;
	      tmp->next->prev = tmp->prev;
	    }
	}
      (tmp) ? (free(tmp)) : (tmp = NULL);
      tmp = NULL;
    }
  return (EXIT_SUCCESS);
}

int
edit_default(t_global *global, t_line **line, char *prompt, char *buff)
{
  prompt = prompt;
  ++global->curser;
  if (my_strlen(buff) == 1 && buff[0] >= 32)
    {
      edit_putlist(line, buff[0]);
      write(1, buff, my_strlen(buff));
    }
  else
    {
      edit_putlist(line, '~');
      write(1, "~", 1);
    }
  return (EXIT_SUCCESS);
}

int
edit_clear(t_global *global, t_line **line, char *prompt, char *buff)
{
  int	cm;

  buff = buff;
  termcap_action(1, CLEAR_MOVE_STRING);
  cm = edit_listlen(*line) - global->curser;
  my_putstr(prompt);
  edit_afflist(*line);
  while ((--cm + 1))
    termcap_action(1, LEFT_MOVE_STRING);
  return (EXIT_SUCCESS);
}

int
edit_control(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;
  char	*flag;
  int	cm;
  int	i;

  prompt = prompt;
  tmp = *line;
  flag = (!my_strncmp(START_EDIT_STRING, buff,
  (my_strlen(START_EDIT_STRING) - 1))) ? LEFT_MOVE_STRING : RIGHT_MOVE_STRING;
  cm = (!my_strncmp(START_EDIT_STRING, buff,
  (my_strlen(START_EDIT_STRING) - 1))) ? global->curser :
  (edit_listlen(*line) - global->curser);
  i = (!my_strncmp(START_EDIT_STRING, buff,
  (my_strlen(START_EDIT_STRING) - 1))) ? -1 : 1;
  termcap_action(cm, flag);
  global->curser = global->curser + (cm * i);
  while (tmp)
    {
      tmp->status = 0;
      if (i > 0 && !tmp->next)
	tmp->status = 1;
      tmp = tmp->next;
    }
  return (EXIT_SUCCESS);
}

t_efunc	*edit_func(void)
{
  t_efunc	*func;

  if ((func = xmalloc(sizeof(*func) * MAX_EDIT_KEYWORD_NUMBER)) == NULL)
    return (NULL);
  func[0] = &edit_delete;
  func[1] = &edit_leftmove;
  func[2] = &edit_rightmove;
  func[3] = &edit_uphistory;
  func[4] = &edit_downhistory;
  func[5] = &edit_suppr;
  func[6] = &edit_clear;
  func[7] = &edit_control;
  func[8] = &edit_control;
  func[9] = &edit_leftmove;
  func[10] = &edit_rightmove;
  func[11] = &edit_delete;
  func[12] = &edit_uphistory;
  func[13] = &edit_swap;
  func[14] = &edit_allstore;
  func[15] = &edit_rightstore;
  func[16] = &edit_leftstore;
  func[17] = &edit_paste;
  func[18] = &edit_switchmove;
  func[19] = &edit_goto_prevspace;
  func[20] = &edit_goto_nextspace;
  func[21] = &edit_globing;
  func[MAX_EDIT_KEYWORD_NUMBER - 1] = &edit_default;
  return (func);
}
