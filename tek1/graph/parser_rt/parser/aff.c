/*
** aff.c for aff in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Feb 14 10:26:05 2012 harold ozouf
** Last update Sun Mar 11 20:18:57 2012 harold ozouf
*/

#include	<unistd.h>
#include	"aff.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    my_putchar(str[i]);
  my_putchar('\n');
}

void	my_putstrn(char *str)
{
  int	i;

  i = -1;
  while (str[++i])
    my_putchar(str[i]);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
