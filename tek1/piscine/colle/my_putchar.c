/*
** my_putchar.c for my_putchar.c in /home/platel_k//projet/piscine/colle
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Oct  8 14:29:32 2011 kevin platel
** Last update Sat Oct 29 23:53:05 2011 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
/*
** Diplay one character
*/
void	my_putchar(char c)
{
  write(1, &c, 1);
}
