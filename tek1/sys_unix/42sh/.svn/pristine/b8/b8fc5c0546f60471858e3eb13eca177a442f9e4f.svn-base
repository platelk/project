/*
** config.h for 42sh in /home/leprov_a//depot/42sh/include
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun Apr 15 20:16:44 2012 alexis leprovost
** Last update Sat May 19 14:35:47 2012 alexis leprovost
*/

#ifndef __CONFIG_H__
#define __CONFIG_H__

#include	"alias.h"
#include	"env.h"

#define PROMPT_CONFIG_STRING	"set prompt"
#define HISTORY_CONFIG_STRING	"set history"
#define	SAVEHIST_CONFIG_STRING	"set savehist"
#define ALIAS_CONFIG_STRING	"alias"
#define AUTOLIST_CONFIG_STRING	"set autolist"
#define	COMPLETE_CONFIG_STRING	"set complete"
#define PATH_CONFIG_STRING	"set prompt"
#define ENV_CONFIG_STRING	"setenv"

#define HISTORY_STRING_NUMBER	2
#define SAVEHIST_STRING_NUMBER	2
#define PROMPT_STRING_NUMBER	2
#define ALIAS_STRING_NUMBER	2
#define ENV_STRING_NUMBER	2

#define	DELIM_HISTORY_STRING	"="
#define	DELIM_SAVEHIST_STRING	"="
#define	DELIM_PROMPT_STRING	"="
#define DELIM_ALIAS_STRING	"'"
#define	DELIM_SPACE_STRING	" "
#define	DELIM_ENV_STRING	"\""

#define	PROMPT_CHAR	'"'

#define	MAX_KEYWORD_NUMBER	8
#define MAX_OPTION_NUMBER	4

#define	MAGIC_STRING	"033"
#define	MAGIC_STRING_LENGTH	3
#define	MAGIC_NUMBER	27

typedef enum e_option
{
  HIST,
  SAVEHIST,
  AUTOLIST,
  COMPLETE
} t_option;

typedef struct s_config
{
  t_alias	*alias;
  int	*option;
  char	*prompt;
  t_env	*env;
} t_config;

typedef int (*t_func)(char *, t_config *);

t_config	*config_parser(char *);
int		config_keyword(char **);
t_func		*config_func(void);
int		config_iskeyword(char *, char **, int);
int		config_history(char *, t_config *);
int		config_savehist(char *, t_config *);
int		config_alias(char *, t_config *);
int		config_prompt(char *, t_config *);
int		config_globing(char *, t_config *);
int		config_env(char *, t_config *);
int		config_comment(char *, t_config *);
int		my_putalias(t_alias **, char *, char *);

void		config_free(t_config *);

#endif
