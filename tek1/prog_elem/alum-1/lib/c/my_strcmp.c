/*
** my_strcmp.c for my_strcmp in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 13:31:07 2011 kevin platel
** Last update Tue Dec 20 15:27:12 2011 kevin platel
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
    {
      i = i + 1;
      if (s1[i] == '\0' && s1[i] == s2[i])
	return (0);
    }
    return (s1[i] - s2[i]);
}
