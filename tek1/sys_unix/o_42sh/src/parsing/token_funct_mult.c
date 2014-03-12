/*
** token_funct_mult.c for token_funct_mult in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 11:00:13 2012 harold ozouf
** Last update Tue Apr 17 12:15:48 2012 harold ozouf
*/


#include	<string.h>
#include	"token.h"
#include	"token_funct.h"

t_bool	is_a_par(t_token **tok, char **str)
{
  if (**str == '(')
    {
      *str += 1;
      add_token(tok, WORD, "(", S_PAR);
      return (TRUE);
    }
  else if (**str == ')')
    {
      *str += 1;
      add_token(tok, WORD, ")", E_PAR);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_an_oper_cond(t_token **tok, char **str)
{
  if (!strncmp("||", *str, 2))
    {
      *str += 2;
      add_token(tok, OR, "||", NONE);
      return (TRUE);
    }
  else if (!strncmp("&&", *str, 2))
    {
      *str += 2;
      add_token(tok, AND, "&&", NONE);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_a_quote(t_token **tok, char **str)
{
  if (**str == '\'')
    add_token(tok, QUOTE, "'", S_QUOTE);
  else if (**str == '\"')
    add_token(tok, QUOTE, "\"", D_QUOTE);
  else if (**str == '`')
    add_token(tok, QUOTE, "`", B_QUOTE);
  else
    return (FALSE);
  *str += 1;
  return (TRUE);
}

t_bool	is_a_red_d(t_token **tok, char **str)
{
  if (!strncmp(">>", *str, 2))
    {
      *str += 2;
      add_token(tok, D_RED_RIGHT, ">>", NONE);
      return (TRUE);
    }
  else if (!strncmp("<<", *str, 2))
    {
      *str += 2;
      add_token(tok, D_RED_LEFT, "<<", NONE);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_a_red_s(t_token **tok, char **str)
{
  if (**str == '>')
    {
      *str += 1;
      add_token(tok, S_RED_RIGHT, ">", NONE);
      return (TRUE);
    }
  else if (**str == '<')
    {
      *str += 1;
      add_token(tok, S_RED_LEFT, "<", NONE);
      return (TRUE);
    }
  else if (**str == '|')
    {
      *str += 1;
      add_token(tok, PIPE, "|", NONE);
      return (TRUE);
    }
 return (FALSE);
}
