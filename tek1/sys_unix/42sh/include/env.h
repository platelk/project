/*
** env.h for env in /home/vink/projet/sys_unix/42sh/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 10 16:49:58 2012 kevin platel
** Last update Sat May 19 13:14:39 2012 kevin platel
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
void    print_env(t_env *);
char	*find_in_env(char *, t_env *);
char	**export_env(t_env *);
t_env	*creat_list_env(char *, t_env *);
void	env_free(t_env *);

#endif
