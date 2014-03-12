/*
** add_in_tab.c for add_in_tab in /home/platel_k//projet/piscine/colle
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Oct 29 22:56:41 2011 kevin platel
** Last update Sun Oct 30 00:59:00 2011 kevin platel
*/

#include <stdlib.h>
#include "my.h"
#include "header.h"

void	add_in_tab(char *str, char c)
{
  int	none;
  char	src[1];

  none = 0;
  src[0] = c;
  src[1] = '\0';
  none = my_strcat(str, src);
}
