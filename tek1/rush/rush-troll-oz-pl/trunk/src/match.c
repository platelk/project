/*
** glob_match.c for glob in /home/vink/projet/sys_unix/42sh/src/globing/globing
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Thu May 10 10:45:46 2012 kevin platel
** Last update Fri Jun  8 18:55:47 2012 kevin platel
*/

int	match(char *str, char *try)
{
  while (str && try && *try)
    {
      if (*str != *try && *str != '*')
	return (0);
      if (str && *str && *str == *try)
	str++;
      if (str && *str == '*')
	{
	  str++;
	  while (*str != *try && *try)
	    try++;
	}
      else if (*try)
	try++;
    }
  while (str && *str == '*')
    str++;
  if (*str == *try)
    return (1);
  return (0);
}
