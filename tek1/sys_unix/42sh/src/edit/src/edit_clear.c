/*
** edit_clear.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 17 11:08:44 2012 alexis leprovost
** Last update Sat May 19 21:12:27 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"global.h"
#include	"edit.h"
#include	"xsys.h"
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
  if ((global->curser[X] > 0 || global->curser[Y] > 0) && tmp &&
      !termcap_delete(1, LEFT_MOVE_STRING, global, -1))
    {
      if (tmp->prev)
	{
	  tmp->prev->status = 1;
	  tmp->prev->next = tmp->next;
	}
      if (tmp->next)
	tmp->next->prev = tmp->prev;
      tmp->prev == NULL ? (*line = tmp->next) : (*line = *line);
      free(tmp);
      tmp = NULL;
    }
  return (EXIT_SUCCESS);
}

static void	suppr_letter(t_line **line)
{
  t_line	*tmp;

  tmp = *line;
  while (tmp && !tmp->status)
    tmp = tmp->next;
  if (tmp)
    tmp = tmp->next;
  else
    tmp = *line;
  if (tmp && tmp->next != NULL)
    tmp->next->prev = tmp->prev;
  if (tmp && tmp->prev != NULL)
    tmp->prev->next = tmp->next;
  if (tmp)
    {
      tmp->prev == NULL ? (*line = tmp->next) : (*line = *line);
      free(tmp);
    }
}

int
edit_suppr(t_global *global, t_line **line, char *prompt, char *buff)
{
  prompt = prompt;
  buff = buff;
  if (edit_cp(*line) < edit_listlen(*line))
    suppr_letter(line);
  termcap_action(1, CD_MOVE_STRING, NULL, 0);
  termcap_display(*line, global);
  return (EXIT_SUCCESS);
}

int
edit_clear(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;

  global = global;
  buff = buff;
  tmp = *line;
  termcap_action(1, CLEAR_MOVE_STRING, NULL, 0);
  termcap_action(1, CURSER_OFF, NULL, 0);
  termcap_prompt(prompt, (global->dom[X] - 1));
  if (edit_cp(*line))
    while (tmp && !tmp->status)
      {
	my_putchar(tmp->letter);
	tmp = tmp->next;
      }
  if (tmp != NULL && tmp->status)
    {
      my_putchar(tmp->letter);
      tmp = tmp->next;
    }
  ultim_func(tmp, global);
  termcap_action((edit_listlen(*line) - edit_cp(*line)),
		 LEFT_MOVE_STRING, global, -1);
  termcap_action(1, CURSER_ON, NULL, 0);
  return (EXIT_SUCCESS);
}
