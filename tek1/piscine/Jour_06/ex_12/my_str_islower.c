/*
** my_str_islower.c for my_str_lower in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 16:32:44 2011 kevin platel
** Last update Mon Oct 10 16:33:20 2011 kevin platel
*/

int     my_str_islower(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 'a' || str[i] > 'z')
        return (0);
      i = i + 1;
    }
  if (i = 1)
    return (0);
  return (1);
}
