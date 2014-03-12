/*
** token_funct_word.c for token_funct_word in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 11:03:27 2012 harold ozouf
** Last update Sat May 19 13:41:36 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"token.h"
#include	"token_funct.h"

t_bool	is_a_inibited_char(t_token **tok, char **str)
{
  char	c[3];

  if (str && *str && **str == '\\')
    {
      *str += 1;
      if (**str)
	{
	  c[0] = '\\';
	  c[1] = **str;
	  c[2] = '\0';
	  if (add_token(tok, INIBIT, c, NONE) == EXIT_FAILURE)
	    return (ERROR);
	  *str += 1;
	  return (TRUE);
	}
    }
  return (FALSE);
}

t_bool	is_a_spacer(t_token **tok, char **str)
{
  if (str && *str && **str == ' ')
    {
      *str += 1;
      if (add_token(tok, SPACE, " ", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  else if (str && *str && **str == '\t')
    {
      *str += 1;
      if (add_token(tok, TAB, "\t", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  return (FALSE);
}

static t_bool	is_a_word_ext(char **str, char **res, int *size, int *i)
{
  while (str && *str && **str != '\0' && is_an_alphanum(str) == TRUE)
    {
      (*size)++;
      if ((*res = realloc(*res, *size)) == NULL)
	return (ERROR);
      (*res)[(*i)++] = **str;
      *str += 1;
    }
  return (TRUE);
}

t_bool	is_a_word(t_token **tok, char **str)
{
  char	*res;
  int	i;
  int	size;

  i = 0;
  if (is_an_alphanum(str) == TRUE)
    {
      if ((res = malloc(sizeof(*res))) == NULL)
	return (ERROR);
      size = 1;
      res[i++] = **str;
      *str += 1;
      if (is_a_word_ext(str, &res, &size, &i) == ERROR)
	return (ERROR);
      if ((res = realloc(res, size + 1)) == NULL)
	return (ERROR);
      res[i] = '\0';
      if (add_token(tok, WORD, res, NONE) == EXIT_FAILURE)
	return (ERROR);
      free(res);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_an_alphanum(char **str)
{
  if (str && *str && **str >= '!' && **str <= '~' && **str != ' ' &&
      **str != '\t'
      && **str != '(' && **str != ')' && **str != '$' && **str != '&'
      && **str != '!' && **str != ';' && **str != '>' && **str != '<'
      && **str != '|' && **str != '\'' && **str != '"' && **str != '`'
      && **str != '\\' && **str != '"')
    return (TRUE);
  return (FALSE);
}
