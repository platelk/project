/*
** edit_utils.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu May 17 11:42:40 2012 alexis leprovost
** Last update Sat May 19 21:28:51 2012 alexis leprovost
*/

#include        <stdio.h>
#include        <stdlib.h>
#include	<unistd.h>

#include        "global.h"
#include        "my.h"
#include        "edit.h"
#include        "get_next_line.h"
#include	"xsys.h"

char	*edit_convertlist(t_line *line)
{
  char	*str;
  int	len;
  int	i;

  i = -1;
  len = edit_listlen(line) + 1;
  if (len <= 0 || (str = xmalloc(sizeof(*str) * len)) == NULL)
    return (NULL);
  while (line)
    {
      str[++i] = line->letter;
      line = line->next;
    }
  str[len - 1] = '\0';
  return (str);
}

t_line	*edit_convertstr(char *str)
{
  t_line	*line;
  int	i;

  line = NULL;
  i = -1;
  if (!str)
    return (NULL);
  while (str[++i])
    edit_putlist(&line, str[i]);
  return (line);
}

static t_line	*special_case(t_line *p1, t_line *p2)
{
  if (p1 == NULL && p2 != NULL)
    return (p2);
  if (p2 == NULL && p1 != NULL)
    return (p1);
  if (p1 == NULL && p2 == NULL)
    return (NULL);
  return (NULL);
}

t_line	*edit_concatlist(t_line *p1, t_line *p2, int n)
{
  t_line	*t1;
  t_line	*t2;

  t1 = p1;
  t2 = p2;
  if (p1 == NULL || p2 == NULL)
    return (special_case(p1, p2));
  (n > edit_listlen(p1)) ? (n = edit_listlen(p1)) : (n = n);
  if (!n)
    {
      while (t2->next)
	t2 = t2->next;
      t2->next = p1;
      return (p2);
    }
  while (--n)
    t1 = t1->next;
  t1->status = 0;
  p2->prev = t1;
  while (t2->next)
    t2 = t2->next;
  t2->next = t1->next;
  t1->next = p2;
  return (p1);
}

int	edit_cp(t_line *line)
{
  int	cp;

  cp = 0;
  while (line && !line->status)
    {
      ++cp;
      line = line->next;
    }
  if (line == NULL)
    return (0);
  return (cp + 1);
}
