/*
** token_funct.c for token_funct.h in /home/ozouf_h//42sh/include
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Mon Apr  9 15:44:05 2012 harold ozouf
** Last update Fri May 18 22:26:05 2012 kevin platel
*/

#include	<stdlib.h>
#include	"token.h"
#include	"token_funct.h"

t_bool	is_a_dollar(t_token **tok, char **str)
{
  if (str && *str && **str == '$')
    {
      *str += 1;
      if (add_token(tok, DOLLARS, "$", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_a_pv(t_token **tok, char **str)
{
  if (str && *str && **str == ';')
    {
      *str += 1;
      if (add_token(tok, PV, ";", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_an_excla(t_token **tok, char **str)
{
  if (str && *str && **str == '!')
    {
      if (add_token(tok, EXCLA, "!", NONE) == EXIT_FAILURE)
	return (ERROR);
      *str += 1;
      return (TRUE);
    }
  return (FALSE);
}

t_bool	is_a_esp(t_token **tok, char **str)
{
  if (str && *str && **str == '&')
    {
      *str += 1;
      if (add_token(tok, ESP, "&", NONE) == EXIT_FAILURE)
	return (ERROR);
      return (TRUE);
    }
  return (FALSE);
}

