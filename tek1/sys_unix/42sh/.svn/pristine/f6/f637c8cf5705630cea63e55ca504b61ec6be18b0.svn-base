/*
** history_create_list.c for 42sh in /home/phalip_z//42sh/src/history/src
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Wed May  9 17:37:54 2012 zoe phalippou
** Last update Sat May 19 16:31:10 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	<string.h>
#include	<unistd.h>

#include	"history_putlist.h"
#include	"config.h"
#include	"get_next_line.h"
#include	"xsys.h"
#include	"t_history.h"
#include	"my.h"

int	history_file_config(t_config *config, t_history *history)
{
  int	size;
  int	fd;

  size = -1;
  if (!config && !config->option)
    return (EXIT_FAILURE);
  while (history && history->next)
    history = history->next;
  while (history && history->prev && config->option[HIST] > ++size)
    history = history->prev;
  if ((fd = xopen(".history", O_CREAT | O_TRUNC | O_WRONLY, S_IRUSR
		  | S_IWUSR | S_IRGRP | S_IROTH, NO)) == -1)
    return (EXIT_FAILURE);
  while (history)
    {
      write(fd, history->time, my_strlen(history->time));
      write(fd, "\n", 1);
      write(fd, history->command, my_strlen(history->command));
      write(fd, "\n", 1);
      history = history->next;
    }
  close(fd);
  return (EXIT_SUCCESS);
}

t_history	*history_list_config(t_config *config,
				     t_history *history, int flag)
{
  int	size;
  t_history *tmp;

  size = 0;
  tmp = history;
  if (!flag)
    if (history_file_config(config, history))
      return (NULL);
  while (tmp && tmp->prev && config && config->option
	 && config->option[SAVEHIST] > size)
    {
      tmp = tmp->prev;
      ++size;
    }
  if (tmp && tmp->next && tmp->prev && tmp->prev->prev)
    tmp->next->prev = free_history(tmp);
  return (history);
}

static void	history_put_list(t_history *element, char *tmp,
				int id_command, t_history **history)
{
  element->command = my_strdup(tmp);
  element->id_cmd = id_command;
  element->next = NULL;
  element->prev = *history;
  free(tmp);
}

static int history_fill_list(t_history **history,
			     char *tmp, int fd, int id_command)
{
  t_history	*element;

  if ((element = xmalloc(sizeof(*element))) == NULL)
    return (-1);
  element->time = my_strdup(tmp);
  free(tmp);
  if ((tmp = get_next_line(fd)) == NULL)
    {
      close(fd);
      return (1);
    }
  history_put_list(element, tmp, id_command, history);
  if (*history)
    (*history)->next = element;
  *history = element;
  return (EXIT_SUCCESS);
}

t_history *history_create_list(t_config *config, t_history **history)
{
  int		fd;
  char		*tmp;
  int		id_command;
  int		flag;

  id_command = 0;
  if ((fd = xopen(".history", O_RDONLY, 0, NO)) != -1)
    while ((tmp = get_next_line(fd)))
      {
	if ((flag = history_fill_list(history, tmp, fd, id_command)) == -1)
	  return (NULL);
	else if (flag == 1)
	  return (history_list_config(config, *history, 0));
	id_command++;
      }
  close(fd);
  return (history_list_config(config, *history, 0));
}
