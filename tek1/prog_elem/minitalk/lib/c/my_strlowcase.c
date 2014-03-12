/*
** my_strlowcase.c for my_strlowcase in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 15:08:57 2011 kevin platel
** Last update Mon Oct 10 15:13:28 2011 kevin platel
*/

char    *my_strlowcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'A' || str[i] <= 'Z')
        str[i] = str[i] + 32;
      i = i + 1;
    }
  return (str);
}
