/*
** my_strncmp.c for my_strncmp.c in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 14:50:53 2011 kevin platel
** Last update Mon Oct 10 17:47:12 2011 kevin platel
*/
int	my_strncmp(char *s1, char *s2, int n)
{
  int   i;

  i = 0;
  while (s1[i] == s2[i] && i != n)
    {
      i = i + 1;
      if (s1[i] == s2[i] && i == n)
        return (0);
    }
  if (s2[i] == '\0')
    return (s1[i] - s2[i]);
  return(-1);
}
