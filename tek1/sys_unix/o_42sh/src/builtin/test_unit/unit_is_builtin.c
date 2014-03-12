/*
** unit_is_builtin.c for test in /home/vink/projet/sys_unix/42sh/src/builtin/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Apr 13 12:47:49 2012 kevin platel
** Last update Mon Apr 16 10:35:08 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include "builtin.h"

int	main()
{
  if (is_builtin("cd") != EXIT_SUCCESS)
    {
      printf("Echec\n");
      return (1);
    }
  else
    printf("Success\n");
  if (is_builtin("ced") == EXIT_SUCCESS)
    {
      printf("Echec\n");
      return (1);
    }
  else
    printf("Success\n");
  return (0);
}
