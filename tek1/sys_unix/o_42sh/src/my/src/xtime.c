/*
** xtime.c for xsys in /home/leprov_a//depot/42sh/src/edit/lib
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 19:26:58 2012 alexis leprovost
** Last update Tue Apr 17 12:46:55 2012 alexis leprovost
*/

#include	"xsys.h"

#define	MAX_TIME_NUMBER	6

char	*xtime(void)
{
  time_t	t;
  struct tm	*current;
  char	*str;

  if ((str = xmalloc(sizeof(*str) * MAX_TIME_NUMBER)) == NULL)
    return (NULL);
  t = time(NULL);
  current = localtime(&t);
  sprintf(str, "%d:%d", current->tm_hour, current->tm_min);
  return (str);
}
