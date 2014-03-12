/*
** main.c for test in /home/vink/projet/sys_unix/42sh/src/globing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 10 16:35:40 2012 kevin platel
** Last update Wed Apr 18 10:12:48 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>

#include "env.h"
#include "my.h"
#include "globing.h"
#include "token.h"
#include "token_funct.h"
#include	"my_rev_list.h"
#include	"reconstruct_token.h"
#include	"check_expression.h"

int	main()
{
  t_token	*tok;
  t_env	*e;
  t_token	*new;

  tok = pars_tokenizer("ls -l $PWD *a*");
  my_rev_list(&tok);
  new = reconstruct_token(tok);
  e = creat_env();
  glob_list(new, e);
  while (new)
    {
      printf("%s ", new->content);
      new = new->next;
    }
  return (0);
}
