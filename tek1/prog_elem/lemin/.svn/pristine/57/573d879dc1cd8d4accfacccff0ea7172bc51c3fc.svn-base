/*
** my_putstr.c for my_putstr in /home/leprov_a//Jour_04
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Thu Oct  6 11:26:03 2011 alexis leprovost
** Last update Mon Apr  2 09:22:56 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"my.h"

void	my_putstr(char *str)
{
  int len;

  len = my_strlen(str);
  if (str == NULL)
    exit(my_puterror("Error: String empty.\n"));
  write(1, str, len);
}
