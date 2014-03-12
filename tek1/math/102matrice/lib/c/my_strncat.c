/*
** my_strncat.c for my_strncat in /home/platel_k//projet/piscine/Jour_07/ex_01
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Oct 11 11:12:49 2011 kevin platel
** Last update Tue Oct 11 11:26:07 2011 kevin platel
*/

char    *my_strncat(char *dest, char *src, int n)
{
  int   i;
  int   j;

  j = 0;
  i = 0;
  while (dest[i])
    i = i + 1;
  while (src[j] && n > j)
    {
      dest[i + j] = src[j];
      j = j + 1;
    }
  dest[i + j] = '\0';
  return (dest);
}
