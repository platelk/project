/*
** my_strlen.c for my_strlen in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 10:44:00 2011 kevin platel
** Last update Tue Nov  1 17:34:18 2011 kevin platel
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    i = i + 1;
  return (i);
}
