/*
** progress_bar.c for progress in /home/guiho_r/tek1/rt/src/display
**
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
**
** Started on  Sun Jun  3 09:21:07 2012 ronan guiho
** Last update Sun Jun  3 16:06:38 2012 ronan guiho
*/

#include <sys/ioctl.h>
#include <stdlib.h>

#include "global.h"
#include "my.h"

t_global	*global_thread;

int		progressbar_display(int pourcent, int size)
{
  int		i;
  int		i1;

  i = -1;
  pourcent += 2;
  if (size < 115)
    return (EXIT_FAILURE);
  size -= 15;
  my_putchar('[');
  while (++i < (pourcent - 1))
    {
      i1 = -1;
      while (++i1 < (size / 100))
	my_putchar('=');
    }
  if (pourcent != 0)
    my_putchar('>');
  i = -1;
  while (++i < ((100 - pourcent) * (size / 100)))
    my_putchar(' ');
  my_putstr("]{");
  my_putnbr(pourcent);
  my_putstr("%}");
  return (EXIT_SUCCESS);
}

int		progressbar_raz(int size)
{
  int		i;

  i = -1;
  while (++i < size)
    my_putchar('\b');
  return (EXIT_SUCCESS);
}

int		progressbar_calc(int i)
{
  double	size;
  int		nb_pixel;
  static int	pourcent;
  struct winsize w;

  nb_pixel = (global_thread->window->x_win * \
	      global_thread->window->y_win);
  size = ((double)nb_pixel / 100.0);
  if (i == (int)size && pourcent <= 100.0)
    {
      ioctl(0, TIOCGWINSZ, &w);
      progressbar_raz(w.ws_col);
      progressbar_display(pourcent++, w.ws_col);
      i = -1;
    }
  return (i);
}
