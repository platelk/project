/*
** token_funct_mult.c for token_funct_mult in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 11:00:13 2012 harold ozouf
** Last update Sat May 19 13:56:43 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<string.h>

#include	"my.h"
#include	"token.h"
#include	"token_funct.h"

t_bool	is_a_par(t_token **tok, char **str)
{
  if (str && *str && **str == '(')
    {
      *str += 1;
      if (add_token(tok, WORD, "(", S_PAR) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  else if (str && *str && **str == ')')
    {
      *str += 1;
      if (add_token(tok, WORD, ")", E_PAR) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_an_oper_cond(t_token **tok, char **str)
{
  if (str && *str && !strncmp("||", *str, 2))
    {
      *str += 2;
      if (add_token(tok, OR, "||", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  else if (str && *str && !strncmp("&&", *str, 2))
    {
      *str += 2;
      if (add_token(tok, AND, "&&", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_a_quote(t_token **tok, char **str)
{
  int	ret;

  if (str && *str && **str == '\'')
    ret = add_token(tok, QUOTE, "'", S_QUOTE);
  else if (str && *str && **str == '\"')
    ret = add_token(tok, QUOTE, "\"", D_QUOTE);
  else if (str && *str && **str == '`')
    ret = add_token(tok, QUOTE, "`", B_QUOTE);
  else
    return (FALSE);
  *str += 1;
  if (ret == EXIT_FAILURE)
    return (ERROR);
  return (TRUE);
}

t_bool	is_a_red_d(t_token **tok, char **str)
{
  if (str && *str && !strncmp(">>", *str, 2))
    {
      *str += 2;
      if (add_token(tok, D_RED_RIGHT, ">>", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  else if (str && *str && !strncmp("<<", *str, 2))
    {
      *str += 2;
      if (add_token(tok, D_RED_LEFT, "<<", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_a_red_s(t_token **tok, char **str)
{
  if (str && *str && **str == '>')
    {
      *str += 1;
      if (add_token(tok, S_RED_RIGHT, ">", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  else if (str && *str && **str == '<')
    {
      *str += 1;
      if (add_token(tok, S_RED_LEFT, "<", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  else if (str && *str && **str == '|')
    {
      *str += 1;
      if (add_token(tok, PIPE, "|", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
 return (FALSE);
}
