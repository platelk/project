/*
** my_strupcase.c for my_strupcase in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 14:54:11 2011 kevin platel
** Last update Mon Oct 10 15:13:39 2011 kevin platel
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i] >= 'a' || str[i] <= 'z')
	str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
