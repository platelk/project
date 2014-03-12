/*
** unit_globing.c for test in /home/vink/projet/sys_unix/42sh/src/globing/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Apr 13 11:45:29 2012 kevin platel
** Last update Mon Apr 16 10:50:22 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glob.h>

#include "globing.h"
#include "utils.h"
#include "my.h"
#include "env.h"
#include "token.h"

int	main()
{
  char	*str;

  str = globing("*i*");
  printf("%s\n", str);
  if (strcmp(str, "Makefile include/ lib/ unit.py unit/") != 0)
    return (1);
  return (0);
}
