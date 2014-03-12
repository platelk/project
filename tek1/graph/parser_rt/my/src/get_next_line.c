/*
** my_get_next_line.c for my_get_next_line in /home/leprov_a//afs/current/warning
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat Jan  7 13:11:07 2012 alexis leprovost
** Last update Mon Apr 16 00:06:14 2012 alexis leprovost
*/

#include	<unistd.h>

#include	"get_next_line.h"
#include	"xsys.h"

int	my_putlist(t_line **begin, char letter)
{
  t_line	*new_element;

  if ((new_element = xmalloc(sizeof(*new_element))) == NULL)
    return (EXIT_FAILURE);
  new_element->letter = letter;
  new_element->next = *begin;
  *begin = new_element;
  return (EXIT_SUCCESS);
}

char	*my_convertlist(t_line *line, int size)
{
  t_line	*tmp;
  char	*str;

  if ((str = xmalloc(sizeof(*str) * (size + 1))) == NULL)
    return (NULL);
  while (size)
    {
      str[--size] = line->letter;
      tmp = line->next;
      free(line);
      line = tmp;
    }
  return (str);
}

char	*get_next_line(const int fd)
{
  t_line	*line;
  char	buff[2];
  char	*str;
  int	i;
  int	len;

  i = 0;
  line = NULL;
  while ((len = read(fd, buff, 1)) > 0 && buff[0] != '\0' && buff[0] != '\n')
    {
      if (my_putlist(&line, buff[0]))
	return (NULL);
      ++i;
    }
  if ((len <= 0 && !i) || (str = my_convertlist(line, i)) == NULL)
    return (NULL);
  return (str);
}
