/*
** error.c for error in /home/platel_k//projet/piscine/Jour_13/cat
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Oct 26 12:33:13 2011 kevin platel
** Last update Wed Oct 24 12:50:38 2012 kevin platel
*/

#include <errno.h>

int	error(char *name)
{
  if (errno == EACCES)
    my_putstr("Permission denied\n");
  if (errno == ENOENT)
    {
      my_putstr("cat: ");
      my_putstr(name);
      my_putstr(" : No such file or directory\n");
    }
  if (errno == EISDIR)
    {
      my_putstr(name);
      my_putstr(" is a directory\n");
    }
  else
    return (1);
}
