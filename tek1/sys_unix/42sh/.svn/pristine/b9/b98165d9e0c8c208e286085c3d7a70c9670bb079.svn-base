/*
** globing.h for globing in /home/vink/projet/sys_unix/42sh/src/globing/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 11 11:18:39 2012 kevin platel
** Last update Sat May 19 13:14:17 2012 kevin platel
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
#define		GLOB_CMD	8
#define		GLOB_ALIAS	16

typedef	t_token	*(*f_glob)(t_token *);

char    *glob_cmd(char *, char *, t_global *);
int     glob_select_flag(char *, int);
t_token *glob_hist(t_token *, t_global *, void **);
t_token	*sep_in_dif_tok(t_token *, char *, int);
void	reset_alias(t_alias *);
t_token	*glob_gest_tok_list(t_token *, t_global *, int, char *);
char	*globing(char *, t_global *, int);
char	*globing_str(char *, t_env *);
char	*globing_env(char *, t_env *, t_global *, int);
t_token  *rep_token_env(t_token *, t_env *);
int     glob_list(t_token **, t_global *, int, int);
char    *glob_alias(char *, t_alias *, int *);
t_token	*glob_gest_alias(t_token *, t_global *);
t_token	*glob_back_quotes(t_token *, t_global *);
int	glob_match(char *, char *);
t_token *glob_make_link(t_token *, t_token *, char *);

#endif
