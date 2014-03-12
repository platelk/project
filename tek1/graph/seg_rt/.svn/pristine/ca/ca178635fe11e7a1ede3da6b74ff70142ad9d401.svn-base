/*
** xml_parser.c for xml in /home/vink/projet/graph/xml/xml_src/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Thu May  3 18:22:44 2012 kevin platel
** Last update Mon May  7 10:40:39 2012 kevin platel
*/

#include	<stdlib.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<sys/stat.h>

#include	"my.h"
#include	"xml_token.h"
#include	"xml_error.h"
#include	"xml_utils.h"
#include	"xml_char.h"
#include	"get_next_line.h"

int	xml_open_file(char *path)
{
  int	fd;

  fd = open(path, O_RDONLY);
  if (fd < 0)
    {
      xml_put_error("can not open file [", 0, "]", NULL);
      return (-1);
    }
  return (fd);
}

t_token	*xml_read_file(int fd)
{
  t_token	*token;
  char	*buffer;
  char  *tmp;
  int	i;

  token = NULL;
  i = 1;
  while ((buffer = get_next_line(fd)))
    {
      tmp = xml_epur_str(buffer);
      if ((tmp[0] != S_BAL_CHAR) || (tmp[my_strlen(tmp) - 1] != E_BAL_CHAR))
	{
	  if (tmp[0] != S_BAL_CHAR)
	    xml_put_synt_error(0, tmp, "Missing open balise char.\n", i);
	  if (tmp[my_strlen(tmp) - 1] != E_BAL_CHAR)
	    xml_put_synt_error(my_strlen(tmp), tmp, "Missing end balise.\n", i);
	  return (NULL);
	}
      token = xml_add_in_token_list(tmp, token, i);
      i++;
      if (tmp)
	free(tmp);
      free(buffer);
    }
  return (token);
}

t_token	*xml_get_file(char *path)
{
  int	fd;
  t_token	*token;

  token = NULL;
  fd = xml_open_file(path);
  if (fd < 0)
    return (NULL);
  token = xml_read_file(fd);
  while (token && token->prev)
    token = token->prev;
  return (token);
}
