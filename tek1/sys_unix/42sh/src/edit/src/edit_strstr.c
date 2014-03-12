/*
** edit_strstr.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 17 17:25:58 2012 alexis leprovost
** Last update Sat May 19 21:27:51 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<unistd.h>

#include	"global.h"
#include	"history_subs_func.h"
#include	"edit.h"
#include	"my.h"
#include	"xsys.h"

static void	aff_rch(t_global *global, t_line *line, char *str, int flag)
{
  int	len;
  int	step;

  len = (edit_listlen(line) - edit_cp(line));
  termcap_action(1, CURSER_OFF, NULL, 0);
  termcap_action(len, RIGHT_MOVE_STRING, global, 1);
  step = global->curser[X];
  if (global->curser[Y] == 0)
    step += global->len;
  termcap_action(1, DOWN_MOVE_STRING, NULL, 0);
  termcap_action(global->dom[X], LEFT_MOVE_STRING, NULL, 0);
  termcap_prompt("bck", (global->dom[X] - 1));
  (flag == 1) ? termcap_prompt(":", (global->dom[X] - 1)) :
    termcap_prompt("?", (global->dom[X] - 1));
  termcap_prompt(str, (global->dom[X] - 1));
  termcap_action(global->dom[X], LEFT_MOVE_STRING, NULL, 0);
  termcap_action(1, UP_MOVE_STRING, NULL, 0);
  termcap_action(step, RIGHT_MOVE_STRING, NULL, 0);
  termcap_action(len, LEFT_MOVE_STRING, global, -1);
  termcap_action(1, CURSER_ON, NULL, 0);
}

static void	clear_rch(t_global *global, t_line *line)
{
  termcap_action(1, CURSER_OFF, NULL, 0);
  termcap_delete(edit_cp(line), LEFT_MOVE_STRING, global, -1);
  termcap_action(1, CD_MOVE_STRING, NULL, 0);
  termcap_action(1, CURSER_ON, NULL, 0);
}

static void
edit_core(char *sol, char *buff, t_global *global, t_line **line)
{
  char	*tmp;

  tmp = NULL;
  if (buff[0] == '\177' && sol[0] != '\0')
    sol[my_strlen(sol) - 1] = '\0';
  else if (buff[0] != '\177' && my_strlen(sol) < (global->dom[X] / 2))
    sol[my_strlen(sol)] = buff[0];
  clear_rch(global, *line);
  (*line) ? edit_freelist(*line) : (*line = NULL);
  tmp = subs_interogation_mark((my_strlen(sol) == 0 ? NULL : sol),
			       global->hist);
  *line = edit_convertstr(tmp);
  ultim_func(*line, global);
  aff_rch(global, *line, sol, (*line == NULL ? (0) : (1)));
  my_clstr(buff, MAX_BUFFER_LENGTH);
}

int
edit_strstr(t_global *global, t_line **line, char *prompt, char *buff)
{
  char	*sol;

  prompt = prompt;
  if ((sol = xmalloc(sizeof(*sol) * (global->dom[X]))) == NULL)
    return (EXIT_FAILURE);
  my_clstr(buff, MAX_BUFFER_LENGTH);
  aff_rch(global, *line, NULL, 0);
  while (read(0, buff, MAX_BUFFER_LENGTH) > 0 &&
	 my_strlen(buff) == 1 && buff[0] >= 32 && global->ctrlc == 0)
    edit_core(sol, buff, global, line);
  termcap_action(1, CD_MOVE_STRING, NULL, 0);
  (sol) ? free(sol) : (sol = NULL);
  return (EXIT_SUCCESS);
}
