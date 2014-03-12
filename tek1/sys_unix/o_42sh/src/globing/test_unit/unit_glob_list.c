/*
** unit_glob_list.c for test in /home/vink/projet/sys_unix/42sh/src/parsing
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Apr 17 14:21:36 2012 kevin platel
** Last update Tue Apr 17 15:35:16 2012 kevin platel
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "my.h"
#include "env.h"
#include "token.h"
#include "globing.h"

int	main()
{
  t_token	*tok;
  t_env	*e;

  tok = pars_tokenizer("ls -l $PWD");
  e = creat_env();
  glob_list(tok, e);
  while (tok)
    {
      printf("%s ", tok->content);
      tok = tok->next;
    }
  return (0);
}
