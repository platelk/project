/*
** my_puterror.c for my_puterror in /home/leprov_a//bdd/source/my
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Dec 29 15:08:14 2011 alexis leprovost
** Last update Mon Apr  2 09:25:48 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"my.h"

int	my_puterror(char *str)
{
  int len;

  if (str == NULL)
    return (EXIT_FAILURE);
  len = my_strlen(str);
  write(2, str, len);
  return (EXIT_SUCCESS);
}
