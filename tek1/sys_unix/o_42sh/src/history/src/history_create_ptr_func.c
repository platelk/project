/*
** create_ptr_func_history.c for 42sh in /home/phalip_z//exos/projets/42sh
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue Apr 10 14:48:51 2012 zoe phalippou
*/

#include	<stdlib.h>
#include	"history_create_ptr_func.h"
#include	"history_subs_func.h"

char	**put_str_subs(void)
{
  char	**type_str;

  type_str = malloc(sizeof(*type_str) * 6);
  type_str[0] = "!";
  type_str[1] = "?";
  type_str[2] = "abcdefghijklmnopkrstuvwxwzABCDEFGHIJKLMNOPQRSTUVWWYZ";
  type_str[3] = "0123456789";
  type_str[4] = "-";
  type_str[5] = NULL;
  return (type_str);
}

ptr_f_history	*create_ptr_func_history(ptr_f_history *subs)
{
  subs[0] = &subs_exclamation_mark;
  subs[1] = &subs_interogation_mark;
  subs[2] = &subs_letter;
  subs[3] = &subs_nbr;
  subs[4] = &subs_back_in_history;
  subs[5] = NULL;
  return (subs);
}
