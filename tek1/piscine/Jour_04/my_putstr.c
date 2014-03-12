/*
** my_putstr.c for my_putstr in /home/platel_k//projet/piscine/Jour_04
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct  6 10:12:04 2011 kevin platel
** Last update Thu Oct  6 10:14:37 2011 kevin platel
*/

int	my_putstr(char *str)
{
  while(*str != '\0')
    {
      my_putchar(*str);
      str = str+1;
    }
}
