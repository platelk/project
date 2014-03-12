/*
** termcap_put.c for 42sh in /home/leprov_a//depot/42sh/src/edit
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Wed Apr 25 11:57:19 2012 alexis leprovost
** Last update Wed Apr 25 13:12:10 2012 alexis leprovost
*/

#include	<termios.h>
#include	<curses.h>
#include	<stdlib.h>
#include	<unistd.h>

#include	"edit.h"
#include	"my.h"

int	termcap_put(int cap)
{
  if (write(1, &cap, 1) == -1)
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
