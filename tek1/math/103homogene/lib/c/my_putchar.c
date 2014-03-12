/*
** my_putchar.c for my_putchar.c in /home/platel_k//lib/c
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 10:23:08 2011 kevin platel
** Last update Wed Nov 23 11:00:19 2011 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
