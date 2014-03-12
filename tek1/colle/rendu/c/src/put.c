/*
** put.c for colle in /home/fontai_t/colle2
** 
** Made by thomas fontaine
** Login   <fontai_t@epitech.net>
** 
** Started on  Thu Apr 26 21:20:36 2012 thomas fontaine
** Last update Thu Apr 26 21:31:29 2012 thomas fontaine
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    my_putchar(str[i++]);
}

void	my_putcharerror(char c)
{
  write(2, &c, 1);
}

void	my_puterr(char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    my_putcharerror(str[i++]);
}
