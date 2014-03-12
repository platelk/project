/*
** config_parser.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun Apr 15 20:18:57 2012 alexis leprovost
** Last update Sat May 19 09:34:46 2012 alexis leprovost
*/

#include	<unistd.h>

#include	"config.h"
#include	"xsys.h"
#include	"get_next_line.h"
#include	"my.h"

static t_config	*config_default()
{
  t_config	*config;

  config = malloc(sizeof(*config));
  if (config == NULL)
    return (NULL);
  config->alias = NULL;
  config->prompt = NULL;
  config->env = NULL;
  config->option = malloc(sizeof(*config->option) * 4);
  if (config->option == NULL)
    return (config);
  config->option[0] = 0;
  config->option[1] = 0;
  config->option[2] = 0;
  config->option[3] = 0;
  return (config);
}

t_config	*config_parser(char *path)
{
  t_config	*config;
  t_func	*func;
  char	*keyword[MAX_KEYWORD_NUMBER];
  char	*tmp;
  int	fd;

  if (config_keyword(keyword) ||
      (config = xmalloc(sizeof(*config))) == NULL ||
      (func = config_func()) == NULL ||
      (fd = xopen(path, O_RDONLY, 0, NO)) < 0 ||
      (config->option = xmalloc(sizeof(int *) * MAX_OPTION_NUMBER)) == NULL)
    return (config_default());
  config->alias = NULL;
  config->prompt = NULL;
  config->env = NULL;
  while ((tmp = get_next_line(fd)))
    {
      func[config_iskeyword(tmp, keyword, MAX_KEYWORD_NUMBER)](tmp, config);
      free(tmp);
    }
  close(fd);
  (func) ? free(func) : (func = NULL);
  return (config);
}
