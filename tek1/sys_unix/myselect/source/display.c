/*
** display.c for display in /home/platel_k/projet/sys_unix/myselect/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Jan 10 11:45:11 2012 kevin platel
** Last update Thu Apr 19 14:02:27 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <ncurses.h>
#include "my.h"
#include "myselect.h"

int	display(t_element *list, int max_lenght)
{
  if (list->cursor == 1)
    put_us(list->name);
  else if (list->is_select == 1)
    put_rv(list->name);
  else
    write(0, list->name, my_strlen(list->name));
  if (list->lenght > max_lenght)
    max_lenght = list->lenght;
  return (max_lenght);
}

int	display_list(t_element *list, t_term *term)
{
  int	max_lenght;
  int	i;
  t_element	*tmp;
  t_element	*tmp2;
  int	lenght;

  lenght = 0;
  tmp = list->prev;
  tmp2 = list;
  while (list != tmp)
    {
      i = 0;
      max_lenght = list->lenght;
      mouv_curs(i, lenght);
      while (list != tmp && i < nb_lin(term))
	{
	  max_lenght = display(list, max_lenght);
	  i++;
	  list = list->next;
	  if (list == tmp)
	    tmp = tmp2;
	  mouv_curs(i, lenght);
	}
      lenght += (max_lenght + TABULATION);
    }
  return (0);
}

int	put_us(char *str)
{
  if (use_termcap("us") == ERROR)
    return (ERROR);
  write(0, str, my_strlen(str));
  if (use_termcap("ue") == ERROR)
    return (ERROR);
  return (0);
}

int	put_rv(char *str)
{
  if (use_termcap("mr") == ERROR)
    return (ERROR);
  write(0, str, my_strlen(str));
  if (use_termcap("me") == ERROR)
    return (ERROR);
  return (0);
}

int	use_termcap(char *cap)
{
  char	*s;

  s = NULL;
  s = tgetstr(cap, NULL);
  if (s == NULL)
    return (EXIT_FAILURE);
  if (tputs(s, 1, &put_c) == -1)
    return (EXIT_FAILURE);
  return (0);
}
