/*
** termcap_display.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 25 16:56:38 2012 alexis leprovost
** Last update Fri May 18 12:35:28 2012 alexis leprovost
*/

#include	<termios.h>
#include	<curses.h>
#include	<stdlib.h>
#include        <sys/ioctl.h>

#include	"global.h"
#include	"edit.h"
#include	"my.h"

int	termcap_ioctl(struct winsize *argp)
{
  if (ioctl(0, TIOCGWINSZ, argp))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

void	ultim_func(t_line *line, t_global *global)
{
  while (line)
    {
      my_putchar(line->letter);
      ++global->curser[X];
      if ((global->curser[X] >= global->dom[X]) ||
	  (global->curser[Y] == 0 &&
	   ((global->curser[X] + global->len) >= global->dom[X])))
	{
	  global->curser[X] = 0;
	  ++global->curser[Y];
	  termcap_action(1, DOWN_MOVE_STRING, NULL, 0);
	  termcap_action(global->dom[X], LEFT_MOVE_STRING, NULL, 0);
	}
      if (global->curser[X] < 0 && global->curser[Y] > 0)
	{
	  global->curser[X] = global->dom[X] - 1;
	  --global->curser[Y];
	  if (global->curser[Y] == 0)
	    global->curser[X] -= global->len;
	  termcap_action(1, UP_MOVE_STRING, NULL, 0);
	  termcap_action(global->dom[X], RIGHT_MOVE_STRING, NULL, 0);
	}
      line = line->next;
    }
}

int	termcap_display(t_line *line, t_global *global)
{
  int	data[2];
  int	len;

  termcap_action(1, CURSER_OFF, NULL, 0);
  len = edit_listlen(line) - edit_cp(line);
  termcap_action(len, RIGHT_MOVE_STRING, global, 1);
  data[X] = global->curser[X];
  data[Y] = global->curser[Y];
  termcap_action(edit_listlen(line), LEFT_MOVE_STRING, global, -1);
  ultim_func(line, global);
  global->curser[X] = data[X];
  global->curser[Y] = data[Y];
  termcap_action(len, LEFT_MOVE_STRING, global, -1);
  termcap_action(1, CURSER_ON, NULL, 0);
  return (EXIT_SUCCESS);
}

int	termcap_prompt(char *str, int limit)
{
  int	i;

  i = -1;
  if (str == NULL)
    return (EXIT_FAILURE);
  while (++i < limit && str[i])
    my_putchar(str[i]);
  return (EXIT_SUCCESS);
}
