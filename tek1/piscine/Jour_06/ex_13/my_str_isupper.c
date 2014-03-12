/*
** my_str_isupper.c for my_str_isupper in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 16:34:07 2011 kevin platel
** Last update Mon Oct 10 16:34:31 2011 kevin platel
*/

int     my_str_isupper(char *str)
{
  int   i;

  i = 0;
  while (str[i])
    {
      if (str[i] < 'A' || str[i] > 'Z')
        return (0);
      i = i + 1;
    }
  if (i = 1)
    return (0);
  return (1);
}
