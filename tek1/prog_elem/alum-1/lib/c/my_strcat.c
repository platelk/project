/*
** my_strcat.c for my_strcat in /home/platel_k//projet/piscine/Jour_07
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Oct 11 10:45:37 2011 kevin platel
** Last update Mon Dec 12 14:06:12 2011 kevin platel
*/

char	*my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  j = 0;
  i = 0;
  while (dest[i])
    i = i + 1;
  while (src[j])
    {
      dest[i + j] = src[j];
      j = j + 1;
    }
  dest[i + j] = '\0';
  return (dest);
}
