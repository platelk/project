/*
** concat_token.c for concat_token in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 11:23:03 2012 harold ozouf
** Last update Thu Apr 12 14:41:45 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<string.h>
#include	"token.h"
#include	"concat_token.h"

t_token	*concat_token(t_token *b, t_token *e, t_t_list i, t_t_spec s)
{
  t_token	*tmp;
  t_token	*new;
  char		*str;
  int		size;

  tmp = b;
  size = 1;
  str = malloc(sizeof(*str));
  str[0] = '\0';
  while (tmp != e->next)
    {
      size += strlen(tmp->content);
      str = realloc(str, size);
      str = strcat(str, tmp->content);
      tmp = tmp->next;
    }
  str = realloc(str, size + 1);
  str[size] = '\0';
  new = malloc(sizeof(*new));
  new->id = i;
  new->spec = s;
  new->content = str;
  return (new);
}


