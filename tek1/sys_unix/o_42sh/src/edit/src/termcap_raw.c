/*
** termcap_canon.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 23 11:45:12 2012 alexis leprovost
** Last update Thu Apr 26 11:35:41 2012 kevin platel
*/

#include	<termios.h>
#include	<stdlib.h>

#include	"edit.h"

int	termcap_raw(struct termios *t, int flag)
{
  if (!flag)
    {
      t->c_lflag &= ~ICANON;
      t->c_cc[VMIN] = 1;
      t->c_cc[VTIME] = 0;
      if (tcsetattr(0, TCSANOW, t) == -1)
	return (EXIT_FAILURE);
    }
  else
    t->c_lflag &= ICANON;
  return (EXIT_SUCCESS);
}

int	termcap_echo(struct termios *t, int flag)
{
  if (!flag)
    {
      t->c_lflag &= ~ECHO;
      if (tcsetattr(0, TCSANOW, t) == -1)
	return (EXIT_FAILURE);
    }
  else
    t->c_lflag &= ECHO;
  return (EXIT_SUCCESS);
}
