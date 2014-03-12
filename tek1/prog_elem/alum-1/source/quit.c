/*
** quit.c for quit in /home/platel_k/projet/sys_unix/myselect/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Jan 11 15:21:10 2012 kevin platel
** Last update Mon Jan 30 16:46:57 2012 kevin platel
*/

#include <stdlib.h>
#include <signal.h>
#include "my.h"
#include "myselect.h"

void	quit_signal(int signal)
{
  signal = signal;
  raw_mode(UNSET);
  echo_mode(SET);
  visible_cursor(SET);
  exit (1);
}

int	free_term_info(t_term *term)
{
  if (term != NULL)
    {
      free(term);
      return (0);
    }
  return (ERROR);
}

int	quit_select(t_element *list, t_term *term, int mode)
{
  raw_mode(UNSET);
  echo_mode(SET);
  visible_cursor(SET);
  if (mode == QUIT)
    return_data(list);
  free_term_info(term);
  return (0);
}
