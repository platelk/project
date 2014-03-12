/*
** my_strncpy.c for my_strncpy in /home/platel_k//projet/piscine/Jour_6
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 10 09:27:43 2011 kevin platel
** Last update Mon Oct 10 10:07:31 2011 kevin platel
*/

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  return (dest);
}
