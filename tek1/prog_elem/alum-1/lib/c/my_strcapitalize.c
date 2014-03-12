/*
** my_strcapitalize.c for my_strcapitalize in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 15:12:36 2011 kevin platel
** Last update Mon Oct 10 15:20:58 2011 kevin platel
*/

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if (str[i - 1] == ' ' || i == 0)
	if (str[i] >= 'a' || str[i] <= 'z')
	  str[i] = str[i] - 32;
      i = i + 1;
    }
  return (str);
}
