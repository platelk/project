/*
** termcap_move.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 25 10:10:00 2012 alexis leprovost
** Last update Sat May 19 21:29:18 2012 alexis leprovost
*/

#include	<termios.h>
#include	<curses.h>
#include	<stdlib.h>

#include	"global.h"
#include	"edit.h"
#include	"my.h"

int	termcap_move(t_global *global, int value, int *wtf)
{
  global->curser[X] += value;
  if (global->curser[X] >= (global->dom[X]) ||
      (global->curser[Y] == 0 &&
       ((global->curser[X] + global->len) >= (global->dom[X]))))
    {
      global->curser[X] = 0;
      ++global->curser[Y];
      termcap_action(1, DOWN_MOVE_STRING, NULL, 0);
      termcap_action(global->dom[X], LEFT_MOVE_STRING, NULL, 0);
      *wtf = 1;
    }
  if (global->curser[X] < 0 && global->curser[Y] > 0)
    {
      global->curser[X] = global->dom[X] - 1;
      --global->curser[Y];
      if (global->curser[Y] == 0)
	global->curser[X] -= global->len;
      termcap_action(1, UP_MOVE_STRING, NULL, 0);
      termcap_action(global->dom[X], RIGHT_MOVE_STRING, NULL, 0);
      *wtf = 1;
    }
  return (EXIT_SUCCESS);
}

int	termcap_action(int size, char *flag, t_global *global, int value)
{
  char	*str;
  int	wtf;

  while ((--size + 1) > 0)
    {
      wtf = 0;
      if (global != NULL && value != 0)
	termcap_move(global, value, &wtf);
      if (!wtf)
	{
	  if ((str = tgetstr(flag, NULL)) == NULL)
	    return (EXIT_FAILURE);
	  else
	    if (tputs(str, 1, &termcap_put))
	      return (EXIT_FAILURE);
	}
    }
  return (EXIT_SUCCESS);
}
