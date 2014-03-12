/*
** edit_list.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 23 18:10:07 2012 alexis leprovost
** Last update Sat Apr 28 14:12:02 2012 alexis leprovost
*/

#include        <stdio.h>
#include        <stdlib.h>
#include	<unistd.h>

#include        "global.h"
#include        "my.h"
#include        "edit.h"
#include        "get_next_line.h"
#include	"xsys.h"

t_line	*edit_concatlist(t_line *p1, t_line *p2, int n)
{
  t_line	*t1;
  t_line	*t2;

  t1 = p1;
  t2 = p2;
  if (p1 == NULL && p2 != NULL)
    return (p2);
  if (p2 == NULL && p1 != NULL)
    return (p1);
  if (p1 == NULL && p2 == NULL)
    return (NULL);
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

void	edit_afflist(t_line *line)
{
  while (line)
    {
      my_putchar(line->letter);
      line = line->next;
    }
}

int	edit_putlist(t_line **begin, char letter)
{
  t_line	*new_element;
  t_line	*tmp;

  tmp = *begin;
  if ((new_element = xmalloc(sizeof(*new_element))) == NULL)
    return (EXIT_FAILURE);
  new_element->letter = letter;
  new_element->status = 1;
  new_element->prev = NULL;
  new_element->next = NULL;
  if (*begin == NULL)
    *begin = new_element;
  else
    {
      while (tmp->next != NULL && !tmp->status)
	tmp = tmp->next;
      if (!tmp->next && !tmp->status)
	{
	  new_element->next = *begin;
	  (*begin)->prev = new_element;
	  *begin = new_element;
	  return (EXIT_SUCCESS);
	}
      new_element->prev = tmp;
      new_element->next = tmp->next;
      tmp->status = 0;
      if (tmp->next)
	tmp->next->prev = new_element;
      tmp->next = new_element;
    }
  return (EXIT_SUCCESS);
}

void	edit_freelist(t_line *line)
{
  t_line	*tmp;

  while (line)
    {
      tmp = (line)->next;
      free(line);
      line = tmp;
    }
  line = NULL;
}

int	edit_listlen(t_line *line)
{
  int	i;

  i = 0;
  while (line != NULL)
    {
      line = line->next;
      ++i;
    }
  return (i);
}

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
