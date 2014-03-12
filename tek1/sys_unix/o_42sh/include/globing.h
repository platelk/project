/*
** globing.h for globing in /home/vink/projet/sys_unix/42sh/src/globing/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 11 11:18:39 2012 kevin platel
** Last update Tue May  1 13:18:04 2012 kevin platel
*/
/*
** globing.h for globing in /home/vink/projet/sys_unix/42sh/src/globing/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 11 11:18:39 2012 kevin platel
** Last update Mon Apr 23 10:49:36 2012 kevin platel
*/

#ifndef	__GLOBING_H__
#define __GLOBING_H__

#include "env.h"
#include "token.h"
#include "t_history.h"
#include "alias.h"
#include "global.h"

#define		NB_GLOB_FUNC	0
#define		G_E_WITH_DOL    1
#define		G_E_WITHOUT_DOL    2

#define		GLOB_DIR	1
#define		GLOB_SLASH	2
#define		GLOB_ENV	4
#define		GLOB_ALI	8

typedef	t_token	*(*f_glob)(t_token *);

t_token	*glob_gest_tok_list(t_token *t, t_global *glob, int flag, char *str);
char	*globing(char *str, t_global *glob, int flag);
char	*globing_str(char *str, t_env *env);
char	*globing_env(char *str, t_env *env, int flag);
t_token  *rep_token_env(t_token *tok, t_env *env);
int     glob_list(t_token *tok, t_global *glob, int i);
char    *glob_alias(char *str, t_alias *alias, int *c);

#endif
