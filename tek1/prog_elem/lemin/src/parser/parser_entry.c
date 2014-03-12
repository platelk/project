/*
** parser_entry.c for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr  4 10:52:16 2012 ronan guiho
** Last update Tue Apr 10 14:51:15 2012 matthieu przybylski
*/

#include <unistd.h>
#include <stdlib.h>

#include "lemin.h"

int		parser_main_room_link(t_glob *global, char **tab, int i)
{
  if ((i = parser_room(global, tab, i + 1)) == -1)
    return (EXIT_FAILURE);
  if ((parser_room_analize(global->room)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  if ((global->ant = parser_init_ant(global)) == NULL)
    return (EXIT_FAILURE);
  if ((parser_link(global->room, tab, i)) == EXIT_FAILURE)
    return (EXIT_FAILURE);
  parser_free_tab(tab);
  return (EXIT_SUCCESS);
}

t_glob		*parser_main()
{
  int		i;
  int		rtrn;
  char		delim[2];
  t_glob	*global;
  char		**tab;
  char		buff[SIZE_BUFFER];

  i = 0;
  if ((global = malloc(sizeof(*global))) == NULL)
    return (NULL);
  delim[0] = DELIM_BUFFER;
  delim[1] = '\0';
  if ((rtrn = read(0, buff, SIZE_BUFFER)) == -1)
    return (NULL);
  buff[rtrn] = '\0';
  if (my_strlen(buff) <= 1)
    return (NULL);
  (buff[rtrn - 1] == '\n') ? my_printf("%s", buff) : my_printf("%s\n", buff);
  if ((tab = my_strtok(buff, delim, TOK_DELIM)) == NULL)
    return (NULL);
  while (tab[i][0] == '#' && tab[i][1] != '#')
    i++;
  global->nb_ant = my_getnbr(tab[i]);
  return (((parser_main_room_link(global, tab, i)) == EXIT_FAILURE) ? \
	  (NULL) : (global));
}
