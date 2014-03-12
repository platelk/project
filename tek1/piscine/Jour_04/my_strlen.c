/*
** my_strlen.c for my_strlen in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 10:44:00 2011 kevin platel
** Last update Thu Oct  6 14:40:14 2011 kevin platel
*/

int	my_strlen(char *str)
{
  int	length;

  length = '0';
  while (*str != '\0')
    {
      str = str + 1;
      length = length + 1;
    }
  my_putchar(length);
}
