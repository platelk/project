/*
** my_strncpy.c for my_strncpy in /home/platel_k//projet/piscine/Jour_6
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Oct 10 09:27:43 2011 kevin platel
** Last update Mon Apr  8 15:58:00 2013 vink
*/

int	my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  if (!dest || !src)
    return (0);
  while (src[i] && dest[i] && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (i);
}
