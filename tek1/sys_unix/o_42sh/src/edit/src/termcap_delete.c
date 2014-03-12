/*
** termcap_clear.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 23 18:34:14 2012 alexis leprovost
** Last update Thu Apr 26 19:41:24 2012 alexis leprovost
*/

#include	<termios.h>
#include	<curses.h>
#include	<stdlib.h>

#include	"edit.h"
#include	"my.h"

int	termcap_delete(int size, char *flag)
{
  while ((--size + 1) > 0)
    {
      if (termcap_action(1, flag) ||
	  termcap_action(1, BACKWARD_STRING))
	return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
