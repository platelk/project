/*
** glob_match.c for glob in /home/vink/projet/sys_unix/42sh/src/globing/globing
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Thu May 10 10:45:46 2012 kevin platel
** Last update Thu May 10 10:58:01 2012 kevin platel
*/

int	glob_match(char *str, char *try)
{
  while (*try)
    {
      if (*str != *try && *str != '*')
	  return (0);
      if (*str == *try)
	str++;
      if (*str == '*')
	{
	  str++;
	  while (*str != *try && *try)
	    try++;
	}
      else if (*try)
	try++;
    }
  while (*str == '*')
    str++;
  if (*str == *try)
    return (1);
  return (0);
}
