/*
** my_puterror.c for colle in /home/leprov_a//depot/colle10/lib
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Thu Apr 26 21:28:03 2012 alexis leprovost
** Last update Thu May  3 18:32:44 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"my.h"

int	my_puterror(char *str)
{
  if (write(2, str, my_strlen(str)) == -1)
    return (EXIT_FAILURE);
  return (EXIT_FAILURE);
}
