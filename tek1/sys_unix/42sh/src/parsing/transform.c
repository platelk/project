/*
** transform.c for transform.c in /home/ozouf_h//42sh
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May 16 18:25:42 2012 harold ozouf
** Last update Wed May 16 18:30:27 2012 harold ozouf
*/

#include	<string.h>
#include	"token.h"

void	transform_inib(t_token *t)
{
  if (t->content[1] == 'a')
    t->content = strdup("\a");
  if (t->content[1] == 'n')
    t->content = strdup("\n");
  if (t->content[1] == 't')
    t->content = strdup("\t");
  if (t->content[1] == 'b')
    t->content = strdup("\b");
  if (t->content[1] == 'v')
    t->content = strdup("\v");
  if (t->content[1] == 'f')
    t->content = strdup("\f");
  if (t->content[1] == 'r')
    t->content = strdup("\r");
}
