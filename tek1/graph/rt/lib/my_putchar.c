/*
** my_putchar.c for pi in /home/leprov_a//depot/colle10/lib
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Apr 19 14:27:31 2012 alexis leprovost
** Last update Mon May 28 18:54:11 2012 jordan vanwalleghem
*/

#include	<stdlib.h>
#include	<unistd.h>

void	my_putchar(char c)
{
  if (write(1, &c, 1) != 1)
    exit(-1);
}
