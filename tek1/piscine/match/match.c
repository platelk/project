/*
** match.c for match in /home/platel_k//projet/piscine/match
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Fri Oct 14 10:49:25 2011 kevin platel
** Last update Fri Dec 16 09:41:35 2011 kevin platel
*/

int	match(char *s1, char *s2)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while(s1[i])
    {
      while (s1[i] == s2[j] || s2[0] == '*')
	{
	  i = i + 1;
	  j = j + 1;
	  if (s1[i] == '\0' && s2[i] == '\0')
	    return (1);
	}
      if (s2[j] == '*' && s2[j + 1] == '\0')
	return (1);
      if (s2[j] == '*')
	  while (s2[j + 1] != s1[i])
	      i = i + 1;
      else
	return (0);
      j = j + 1;
    }
  return (1);
}
