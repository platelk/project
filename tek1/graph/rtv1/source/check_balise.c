/*
** check_balise.c for check_balise in /home/vink/projet/graph/rtv1/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Feb  8 10:57:39 2012 kevin platel
** Last update Thu Feb  9 12:59:40 2012 kevin platel
*/

#include <stdlib.h>

#include "my.h"
#include "rt.h"
#include "error_file.h"

int	check_balise(char *line, char *name)
{
  char	**tab;
  int	i;
  int	error;

  i = 0;
  tab = my_strtok(line, " \t\n");
  error = 0;
  while (tab && tab[i])
    i++;
  if (tab == NULL)
    error = (ERROR_LINE_EMPTY);
  else if (tab[0] == NULL)
    error = (ERROR_LINE_SPACE);
  else if (tab[0][0] != OPEN_CHAR)
    error =(ERROR_OPEN_BALISE);
  else if (tab[i - 1][my_strlen(tab[i - 1]) - 1] != CLOSE_CHAR)
    error = (ERROR_CLOSE_BALISE);
  else if (my_find_str(line, name) < 0)
    error = (ERROR_NO_DEF_NAME);
  freewordtab(tab);
  return (error);
}

void	print_balise_error(int error)
{
  if (error == ERROR_LINE_EMPTY)
    my_printf("Error, line is empty !\n");
  if (error == ERROR_LINE_SPACE)
    my_printf("Error, line is full space/tab !\n");
  if (error == ERROR_OPEN_BALISE)
    my_printf("Error, line have no valid open char !\n");
  if (error == ERROR_CLOSE_BALISE)
    my_printf("Error, line have no valid close char !\n");
  if (error == ERROR_NO_DEF_NAME)
    my_printf("Error, name is not valid her !\n");
}
