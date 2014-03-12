/*
** get_data.c for get_data in /home/platel_k/projet/bsq/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Dec  8 11:10:12 2011 kevin platel
** Last update Sun Jan 15 11:47:56 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

char	*epur_str(char *line)
{
  char	**tab;
  char	*str;
  int	i;

  i = 0;
  tab = my_str_to_wordtab(line);
  while (tab[i])
    {
      if (my_strlen(tab[i]) > 1)
	{
	  my_printf("Please enter a valid map\n");
	  exit (1);
	}
      i++;
    }
  str = malloc((i + 1) * sizeof(char));
  str[0] = '\0';
  i = 0;
  while (tab[i])
    {
      str = my_strcat(str, tab[i]);
      i++;
    }
  return (str);
}

char	**get_data(char *link)
{
  int   fd;
  char  *line;
  char  **data;
  int	j;

  j = 1;
  fd = open(link, O_RDONLY);
  if (fd == -1)
    exit(0);
  if ((line  = get_next_line(fd)) == NULL)
    exit (0);
  data = malloc((my_strlen(line) + 1) * sizeof(*data));
  data[0] = epur_str(line);
  if (data == NULL)
    return (0);
  while ((line = get_next_line(fd)) != NULL)
    {
      data[j] = epur_str(line);
      free(line);
      j++;
    }
  data[j] = NULL;
  return (data);
}
