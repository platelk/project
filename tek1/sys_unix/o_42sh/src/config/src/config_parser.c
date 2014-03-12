/*
** config_parser.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun Apr 15 20:18:57 2012 alexis leprovost
** Last update Wed Apr 18 13:42:39 2012 alexis leprovost
*/

#include	<unistd.h>

#include	"config.h"
#include	"xsys.h"
#include	"get_next_line.h"
#include	"my.h"

t_config	*config_parser(char *path)
{
  t_config	*config;
  t_func	*func;
  char	**keyword;
  char	*tmp;
  int	fd;

  if ((config = xmalloc(sizeof(*config))) == NULL ||
      (keyword = config_keyword()) == NULL ||
      (func = config_func()) == NULL ||
      (fd = xopen(path, O_RDONLY, 0, NO)) < 0 ||
      (config->option = xmalloc(sizeof(int *) * MAX_OPTION_NUMBER)) == NULL)
    return (NULL);
  config->alias = NULL;
  config->prompt = NULL;
  config->env = NULL;
  while ((tmp = get_next_line(fd)))
    {
      func[config_iskeyword(tmp, keyword)](tmp, config);
      free(tmp);
    }
  close(fd);
  return (config);
}
