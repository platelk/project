/*
** main.c for main in /home/platel_k/projet/sys_unix/myselect/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Dec 29 17:14:16 2011 kevin platel
** Last update Tue Feb 19 17:49:56 2013 vink
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "myselect.h"

int	put_c(int cap)
{
  write(2, &cap, 1);
  return (0);
}

int	check_attr()
{
  raw_mode(SET);
  return (ERROR);
}

int	main(int ac, char **av, char **envp)
{
  t_element	*list;
  t_term	*term;
  int	action;

  tgetent(NULL, get_term(envp));
  disable_signal();
  init_select(&list, &term, av, ac);
  while (action != QUIT && action != ECHAP)
    {
      screen_clean();
      if (can_display_list(list, list->prev, term) == ERROR)
	my_printf("Can't display list\n");
      else
	display_list(list, term);
      check_attr();
      action = treatment_of_data(get_data(term), list);
    }
  screen_clean();
  quit_select(list, term, action);
  return (0);
}
