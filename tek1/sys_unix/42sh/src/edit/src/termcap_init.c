/*
** termcap_init.c for 42sh in /home/leprov_a//depot/42sh/src/termcap/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 23 11:00:10 2012 alexis leprovost
** Last update Fri May 18 22:05:59 2012 kevin platel
*/

#include        <term.h>
#include	<curses.h>
#include	<stdlib.h>

#include	"edit.h"
#include	"env.h"

int	termcap_init(t_env *env)
{
  char	*term;

  if ((term = find_in_env(TERM_STRING, env)) == NULL ||
      tgetent(NULL, term) <= 0)
    {
      tgetent(NULL, DEFAULT_TERM_STRING);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
