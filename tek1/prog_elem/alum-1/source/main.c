/*
** main.c for main in /home/platel_k/projet/sys_unix/myselect/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Dec 29 17:14:16 2011 kevin platel
** Last update Wed Apr  4 09:40:11 2012 kevin platel
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

void	gest_bot(t_element **list, t_term *term, int *action, int *ia)
{
  gest_display(list, term, action, ia);
  if ((*list = bot(*list)) == NULL)
    {
      my_printf("\nPlayer 1 Win !\n");
      exit(1);
    }
  sleep(1);
  action = BOT;
  gest_display(list, term, action, ia);
  action = BOT;
  gest_display(list, term, action, ia);
}

int	main(int ac, char **av, char **envp)
{
  t_element	*list;
  t_term	*term;
  int	action;
  int	ia;

  tgetent(NULL, get_term(envp));
  if (init_select(&list, &term, av, ac) == ERROR)
    return (0);
  action = 0;
  ia = 1;
  while (list && action != QUIT && action != ECHAP && action != END)
    {
      gest_display(&list, term, action, ia);
      if (action != SELECT)
	action = treatment_of_data(get_data(term), &list);
      if (action == SELECT && list != NULL && ia == 1)
	gest_bot(&list, term, action, ia);
      if ((list == NULL) || (list == list->next && (nbr_alum(list) <= 1)))
	action = END;
    }
  return (0);
}
