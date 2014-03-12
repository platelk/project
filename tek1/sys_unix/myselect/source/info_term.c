/*
** info_term.c for info_term.c in /home/platel_k/projet/sys_unix/myselect/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 10 15:54:18 2012 kevin platel
** Last update Thu Apr 19 14:00:16 2012 kevin platel
*/

#include <stdlib.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <curses.h>
#include "my.h"
#include "myselect.h"

int	can_display_list(t_element *list, t_element *begin,  t_term *term)
{
  int	max_lenght;
  int	i;
  int	dec;

  dec = TABULATION;
  if (list != begin)
    {
      while (list != begin)
	{
	  i = 0;
	  max_lenght = (list->lenght) + dec;
	  while (i < nb_lin(term) && list != begin)
	    {
	      if ((list->lenght) + dec > max_lenght)
		max_lenght = (list->lenght) + dec;
	      if (max_lenght > nb_col(term))
		return (ERROR);
	      list = list->next;
	      i++;
	    }
	  dec = max_lenght;
	}
      return (0);
    }
  return (ERROR);
}

int	nb_col(t_term *term)
{
  int	col;
  struct winsize winsize;

  if (ioctl(term->fd, TIOCGWINSZ, &winsize) < 0)
    return (ERROR);
  col = winsize.ws_col;
  return (col);
}

int	nb_lin(t_term *term)
{
  int	lin;
  struct winsize winsize;

  if (ioctl(term->fd, TIOCGWINSZ, &winsize) < 0)
    return (ERROR);
  lin = winsize.ws_row;
  return (lin);
}

t_term	*init_term_info(void)
{
  t_term	*term;

  term = malloc(sizeof(*term));
  if (term == NULL)
    return (NULL);
  term->fd = 0;
  term->cursor_mouv = tgetstr("cm", NULL);
  term->cursor_vi = tgetstr("vi", NULL);
  term->cursor_ve = tgetstr("ve", NULL);
  term->clear = tgetstr("cl", NULL);
  return (term);
}
