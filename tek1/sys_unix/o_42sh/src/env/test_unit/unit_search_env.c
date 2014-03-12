/*
** unit_search_env.c for test in /home/vink/projet/sys_unix/42sh/src/env
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Apr 16 14:00:48 2012 kevin platel
** Last update Mon Apr 16 14:06:28 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "env.h"
#include "my.h"

int	main()
{
  t_env	*e;

  e = creat_env();
  if (find_in_env("TEST_SD_MOT", e) != NULL)
    {
      printf("Erreur lors d'une recherche d'un element inexistant\n");
      return (1);
    }
  if (find_in_env("PWD", e) == NULL)
    {
      printf("Erreur lors d'une recherche d'un element existant\n");
      return (1);
    }
  if (strcmp(find_in_env("EDITOR", e), "emacs") != 0)
    {
      printf("Erreur de recuperation\n");
      return (1);
    }
  return (0);
}
