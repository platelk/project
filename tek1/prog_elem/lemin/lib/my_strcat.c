/*
** my_strcat.c for my_strcat in /home/leprov_a//afs
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Tue Oct 11 13:32:43 2011 alexis leprovost
** Last update Tue Dec 27 15:44:06 2011 alexis leprovost
*/

char	*my_strcat(char *dest, char *src)
{
  char *ptr;

  ptr = dest;
  while (*dest != '\0')
    dest += 1;
  while (*src != '\0')
    {
      *dest = *src;
      dest += 1;
      src += 1;
    }
  *dest = '\0';
  dest = ptr;
  return (dest);
}
