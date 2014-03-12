/*
** edit_list.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 23 18:10:07 2012 alexis leprovost
** Last update Sat May 19 11:19:12 2012 alexis leprovost
*/

#include        <stdio.h>
#include        <stdlib.h>
#include	<unistd.h>

#include        "global.h"
#include        "my.h"
#include        "edit.h"
#include        "get_next_line.h"
#include	"xsys.h"

void	edit_afflist(t_line *line)
{
  while (line)
    {
      my_putchar(line->letter);
      line = line->next;
    }
}

static void	add_element(t_line **begin, t_line *new_element)
{
  t_line	*tmp;

  tmp = *begin;
  while (tmp && tmp->next != NULL && !tmp->status)
    tmp = tmp->next;
  if (!tmp->next && !tmp->status)
    {
      new_element->next = *begin;
      (*begin)->prev = new_element;
      *begin = new_element;
    }
  else
    {
      new_element->prev = tmp;
      new_element->next = tmp->next;
      tmp->status = 0;
      if (tmp->next)
	tmp->next->prev = new_element;
      tmp->next = new_element;
    }
}

int	edit_putlist(t_line **begin, char letter)
{
  t_line	*new_element;

  if ((new_element = xmalloc(sizeof(*new_element))) == NULL)
    return (EXIT_FAILURE);
  new_element->letter = letter;
  new_element->status = 1;
  new_element->prev = NULL;
  new_element->next = NULL;
  if (*begin == NULL)
    *begin = new_element;
  else
    add_element(begin, new_element);
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
