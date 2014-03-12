/*
** aff_tree.c for aff_tree.c in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Thu Apr 19 13:14:24 2012 harold ozouf
** Last update Mon Apr 23 21:11:40 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"token.h"
#include	"tree.h"

static void	aff_space(int nbr)
{
  int	i;

  i = -1;
  while (++i < nbr)
    printf(" ");
}

static void	toto(t_node *rt, int space)
{
  t_child	*ch;

  ch = rt->child;
  if (rt)
    while (ch)
      {
	if (ch->nd)
	  {
	    aff_space(space);
	    if (ch->nd->id == PIPE)
	      printf("|____pipe\n");
	    if (ch->nd->id == CMD)
	      printf("|____cmd %s\n", ch->nd->content);
	    if (ch->nd->id == OR)
	      printf("|____OR\n");
	    if (ch->nd->id == AND)
	      printf("|____AND\n");
	    if (ch->nd->id == ARG)
	      printf("|____arg %s\n",  ch->nd->content);
	    if (ch->nd->id == S_RED_LEFT || ch->nd->id == S_RED_RIGHT || ch->nd->id == D_RED_LEFT || ch->nd->id == D_RED_RIGHT)
	      printf("|____red %d \n", ch->nd->id);
	    toto(ch->nd, space + 5);
	  }
	ch = ch->next;
      }
}


void	aff_tree(t_node *root)
{
  t_child	*tmp_c;

  printf("pv:\n");
  tmp_c = root->child;
  while (tmp_c)
    {
      if (tmp_c->nd->id == PIPE)
	printf("|____pipe\n");
      if (tmp_c->nd->id == CMD)
	printf("|____cmd %s\n", tmp_c->nd->content);
      if (tmp_c->nd->id == OR)
	printf("|____OR\n");
      if (tmp_c->nd->id == AND)
	printf("|____AND\n");
      if (tmp_c->nd->id == ARG)
	printf("|____arg %s\n",  tmp_c->nd->content);
      if (tmp_c->nd->id == S_RED_LEFT || tmp_c->nd->id == S_RED_RIGHT || tmp_c->nd->id == D_RED_LEFT || tmp_c->nd->id == D_RED_RIGHT)
	printf("|____red %d \n", tmp_c->nd->id);
      toto(tmp_c->nd, 5);
      tmp_c = tmp_c->next;
    }
  printf("_______________________________________________________\n\n\n");
}
