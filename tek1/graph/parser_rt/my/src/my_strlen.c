/*
** my_strlen.c for my_strlen in /home/leprov_a//Jour_04
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Thu Oct  6 13:49:39 2011 alexis leprovost
** Last update Tue Apr 17 12:45:33 2012 alexis leprovost
*/

int	my_strlen(char *str)
{
  int i;

  i = 0;
  if (!str)
    return (0);
  while (str[i] != '\0')
    ++i;
  return (i);
}
