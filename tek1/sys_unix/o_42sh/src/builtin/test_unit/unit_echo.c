/*
** unit_echo.c for test in /home/vink/projet/sys_unix/42sh/src/builtin/src/echo
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Apr 16 11:23:19 2012 kevin platel
** Last update Mon Apr 16 13:11:17 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "builtin.h"

int	main()
{
  char	*tab[4];

  tab[0] = "-n";
  tab[1] = "Salut";
  tab[2] = "bouh";
  tab[3] = NULL;

  if (strcmp(search_in_tab("-n", tab), "-n") != 0)
    {
      printf("%s\n", search_in_tab("-e", tab));
      return (1);
    }
  if (search_in_tab("-a", tab) != NULL)
    {
      printf("Error");
      return (1);
    }
  echo(tab);
  return (0);
}
