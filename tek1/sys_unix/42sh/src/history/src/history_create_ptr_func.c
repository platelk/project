/*
** history_create_ptr_func.c for hist in /home/vink/projet/sys_unix/42sh/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May  8 22:56:09 2012 kevin platel
** Last update Sat May 12 10:19:39 2012 zoe phalippou
*/

#include	<stdlib.h>

#include	"history_create_ptr_func.h"
#include	"history_subs_func.h"
#include	"xsys.h"
#include	"my.h"

char	**put_str_subs(void)
{
  char	**type_str;

  if ((type_str = xmalloc(sizeof(*type_str) * 7)) == NULL)
    return (NULL);
  type_str[0] = "!";
  type_str[1] = "?";
  type_str[2] = "abcdefghijklmnopkrstuvwxwzABCDEFGHIJKLMNOPQRSTUVWWYZ";
  type_str[3] = "0123456789";
  type_str[4] = "-";
  type_str[5] = "$";
  type_str[6] = NULL;
  return (type_str);
}

ptr_f_history	*create_ptr_func_history(ptr_f_history *subs)
{
  subs[0] = &subs_exclamation_mark;
  subs[1] = &subs_interogation_mark;
  subs[2] = &subs_letter;
  subs[3] = &subs_nbr;
  subs[4] = &subs_back_in_history;
  subs[5] = &subs_dollar;
  subs[6] = NULL;
  return (subs);
}
