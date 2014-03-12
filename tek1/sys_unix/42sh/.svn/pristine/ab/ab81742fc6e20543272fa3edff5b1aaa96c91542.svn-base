/*
** sh.h for sh in /home/vink/projet/sys_unix/42sh
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 18 20:38:46 2012 kevin platel
** Last update Sat May 19 13:15:13 2012 kevin platel
*/

#ifndef	__SH_H__
#define __SH_H__

#include	"token.h"
#include	"my_rev_list.h"
#include	"reconstruct_token.h"
#include	"check_expression.h"
#include	"env.h"
#include	"alias.h"
#include	"t_history.h"
#include	"global.h"

#define		EXIT_CHILD	3

t_token	*creat_list_token(char *, t_global *, int);
t_node	*parsing_func(char *, t_global *, int);
char    *get_cmd_in_list(t_token *);
t_token	*analyse_cmd(char *);
void	sh_free(t_global *, t_node *, char *);

#endif
