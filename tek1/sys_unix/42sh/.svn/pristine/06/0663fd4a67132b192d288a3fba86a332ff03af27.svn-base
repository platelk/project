/*
** puterror.c for puterror in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Apr 11 17:03:27 2012 harold ozouf
** Last update Sun Apr 15 16:09:05 2012 harold ozouf
*/

#include	<stdio.h>
#include	"token.h"

t_bool	puterror(char *err, char *content)
{
  if (content)
    fprintf(stderr, "%s%s.\n", err, content);
  else
    fprintf(stderr, "%s.\n", err);
  return (ERROR);
}
