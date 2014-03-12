/*
** env.h for env in /home/vink/projet/sys_unix/42sh/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 10 16:49:58 2012 kevin platel
** Last update Wed Apr 18 14:51:36 2012 alexis leprovost
*/

#ifndef	__ENV_H__
#define __ENV_H__

#define SEP_ENV	"="
#define CHAR_VAR_ENV '$'

extern char **environ;

typedef struct s_env
{
  char *name;
  char *value;

  struct s_env *next;
  struct s_env *prev;
} t_env;

t_env	*creat_env(void);
void    print_env(t_env *env);
char	*find_in_env(char *name, t_env *env);
char	**export_env(t_env *env);
t_env	*creat_list_env(char *str, t_env *env);

#endif
