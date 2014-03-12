/*
** my_putchar.c for my_putchar.c in /u/all/guiho_r/rendu/piscine/Jour_03
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue Oct 11 09:48:33 2011 ronan guiho
** Last update Sun Dec 11 16:25:50 2011 ronan guiho
*/
#include <unistd.h>
#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
