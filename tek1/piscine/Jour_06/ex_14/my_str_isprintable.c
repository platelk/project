/*
** my_str_isprintable.c for my_str_isprintable in /home/platel_k//projet/piscine/Jour_6
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Oct 10 16:36:00 2011 kevin platel
** Last update Fri Nov  2 18:22:08 2012 kevin platel
*/

int     my_str_isprintable(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 21 || str[i] <= 127)
        return (0);
      i = i + 1;
    }
  if (i = 1)
    return (0);
  return (1);
}
