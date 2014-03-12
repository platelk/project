/*
** config_func.c for 42sh in /home/leprov_a//depot/42sh/src/config/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 01:11:03 2012 alexis leprovost
** Last update Wed Apr 25 11:13:45 2012 alexis leprovost
*/

#include	"config.h"
#include	"xsys.h"
#include	"my_strtok.h"
#include	"my.h"

int	config_comment(char *str, t_config *config)
{
  str = str;
  config = config;
  return (EXIT_SUCCESS);
}

t_func	*config_func(void)
{
  t_func	*func;

  if ((func = xmalloc(sizeof(*func) * MAX_KEYWORD_NUMBER)) == NULL)
    return (NULL);
  func[0] = &config_prompt;
  func[1] = &config_history;
  func[2] = &config_savehist;
  func[3] = &config_alias;
  func[4] = &config_globing;
  func[5] = &config_globing;
  func[6] = &config_env;
  func[7] = &config_comment;
  return (func);
}
