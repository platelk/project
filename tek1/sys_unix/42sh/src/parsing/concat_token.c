/*
** concat_token.c for concat_token in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 11:23:03 2012 harold ozouf
** Last update Fri May 18 13:56:28 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<string.h>
#include	"token.h"
#include	"concat_token.h"

t_token	*cat_token(t_token *b, t_token *e, t_t_list i, t_t_spec s)
{
  t_token	*tmp;
  t_token	*new;
  char		*str;
  int		size;

  size = 1;
  if ((tmp = b) && (str = malloc(sizeof(*str))) == NULL)
    return (NULL);
  str[0] = '\0';
  while (tmp != e->next)
    {
      size += strlen(tmp->content);
      str = realloc(str, size);
      str = strcat(str, tmp->content);
      tmp = tmp->next;
    }
  if ((str = realloc(str, size + 1)) == NULL)
    return (NULL);
  str[size] = '\0';
  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->id = i;
  new->spec = s;
  new->content = str;
  return (new);
}
