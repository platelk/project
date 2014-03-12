/*
** main.c for main_colle in /home/platel_k//projet/piscine/colle
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Oct  8 14:14:58 2011 kevin platel
** Last update Sat Oct 29 23:34:01 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "header.h"

void	colle(char *test);

int	main(int argc, char **argv) 
{
  int x;
  int y;

  x = 5;
  y = 5;
  colle(argv[0]);
  return (0);
}
