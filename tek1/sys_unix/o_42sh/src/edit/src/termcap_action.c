/*
** termcap_move.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 25 10:10:00 2012 alexis leprovost
** Last update Thu Apr 26 19:40:00 2012 alexis leprovost
*/

#include	<termios.h>
#include	<curses.h>
#include	<stdlib.h>

#include	"edit.h"
#include	"my.h"

int	termcap_action(int size, char *flag)
{
  char	*str;

  while ((--size + 1))
    {
      if ((str = tgetstr(flag, NULL)) == NULL)
	return (EXIT_FAILURE);
      else
	if (tputs(str, 1, &termcap_put))
	  return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
