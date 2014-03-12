/*
** token_funct_word.c for token_funct_word in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 11:03:27 2012 harold ozouf
** Last update Thu Apr 12 17:47:51 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"token.h"
#include	"token_funct.h"

t_bool	is_a_inibited_char(t_token **tok, char **str)
{
  char	c[2];

  if (**str == '\\')
    {
      *str += 1;
      if (**str)
	{
	  c[0] = **str;
	  c[1] = '\0';
	  add_token(tok, INIBIT, c, NONE);
	  *str += 1;
	  return (TRUE);
	}
    }
  return (FALSE);
}

t_bool	is_a_spacer(t_token **tok, char **str)
{
  if (**str == ' ')
    {
      *str += 1;
      add_token(tok, SPACE, " ", NONE);
      return (TRUE);
    }
  else if (**str == '\t')
    {
      *str += 1;
      add_token(tok, TAB, "\t", NONE);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_a_word(t_token **tok, char **str)
{
  char	*res;
  int	i;
  int	size;

  i = 0;
  if (is_an_alphanum(str) == TRUE)
    {
      res = malloc(sizeof(*res));
      size = 1;
      res[i++] = **str;
      *str += 1;
      while (**str != '\0' && is_an_alphanum(str) == TRUE)
	{
	  size++;
	  res = realloc(res, size);
	  res[i++] = **str;
	  *str += 1;
	}
      res = realloc(res, size + 1);
      res[i] = '\0';
      add_token(tok, WORD, res, NONE);
      free(res);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_an_alphanum(char **str)
{
  if (**str >= '!' && **str <= '~' && **str != ' ' && **str != '\t'
      && **str != '(' && **str != ')' && **str != '$' && **str != '&'
      && **str != '!' && **str != ';' && **str != '>' && **str != '<'
      && **str != '|' && **str != '\'' && **str != '"' && **str != '`'
      && **str != '\\' && **str != '"')
    return (TRUE);
  return (FALSE);
}
