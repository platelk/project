/*
** my_get_next_line.c for my_get_next_line in /home/leprov_a//afs/current/warning
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat Jan  7 13:11:07 2012 alexis leprovost
** Last update Mon Apr  2 14:58:37 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>

#include	"get_next_line.h"
#include	"my.h"

void	my_put_letter_in_list(t_line **line, char letter)
{
  t_line	*new_letter;
  t_line	*tmp;

  tmp = *line;
  if ((new_letter = malloc(sizeof(*new_letter))) == NULL)
    exit(my_puterror("Error: Could not alloc\n"));
  new_letter->next = NULL;
  new_letter->letter = letter;
  if (*line == NULL)
    *line = new_letter;
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_letter;
    }
}

void	my_free_line(t_line *line)
{
  t_line	*tmp;

  while (line != NULL)
    {
      tmp = line->next;
      free(line);
      line = tmp;
    }
  free(line);
}

int	my_size_line(t_line *line)
{
  int	i;

  i = 0;
  while (line != NULL)
    {
      line = line->next;
      i++;
    }
  return (i);
}

char	*my_fill_str(t_line *line)
{
  char	*str;
  int	len;
  int	i;

  i = 0;
  len = my_size_line(line) + 1;
  if ((str = malloc(sizeof(*str) * len)) == NULL)
    exit(my_puterror("Error: Could not alloc.\n"));
  while (i < len - 1)
    {
      str[i] = line->letter;
      line = line->next;
      i++;
    }
  str[i] = '\0';
  return (str);
}

char	*get_next_line(int fd)
{
  t_line	*line;
  char	buff[2];
  char	*str;
  int	i;
  int	len;

  i = 0;
  line = NULL;
  len = read(fd, buff, 1);
  if (len <= 0)
    return (NULL);
  while (buff[0] != '\n' && buff[0] != '\0' && len != 0)
    {
      my_put_letter_in_list(&line, buff[0]);
      len = read(fd, buff, 1);
      i++;
    }
  str = my_fill_str(line);
  my_free_line(line);
  return (str);
}
