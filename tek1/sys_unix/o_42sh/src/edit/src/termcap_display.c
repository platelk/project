/*
** termcap_display.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 25 16:56:38 2012 alexis leprovost
** Last update Thu Apr 26 19:44:34 2012 alexis leprovost
*/

#include	<termios.h>
#include	<curses.h>
#include	<stdlib.h>

#include	"edit.h"
#include	"my.h"

int	termcap_display(t_line *line, int cm)
{
  int	len;

  len = edit_listlen(line) - cm;
  termcap_action(cm, LEFT_MOVE_STRING);
  while (line)
    {
      my_putchar(line->letter);
      line = line->next;
    }
  termcap_action(len, LEFT_MOVE_STRING);
  return (EXIT_SUCCESS);
}
