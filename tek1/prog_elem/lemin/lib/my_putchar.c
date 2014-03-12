/*
** my_putchar.c for my_putchar in /home/leprov_a//Jour_04
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Oct  6 15:56:12 2011 alexis leprovost
** Last update Mon Jan 16 12:33:32 2012 alexis leprovost
*/

#include	<unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
