/*
** main.c for main in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Apr 10 15:42:41 2012 harold ozouf
** Last update Wed Apr 18 18:55:52 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"token.h"
#include	"my_rev_list.h"
#include	"reconstruct_token.h"
#include	"check_expression.h"

void	asc(t_node *rt)
{
  t_child	*c;
  t_child	*d;
  t_child	*e;
  t_child	*f;
  if (rt)
    {
      printf("n1: id = %d, content = %s\n", rt->id, rt->content);
      c = rt->child;
      while (c)
	{
	  printf("n2: id = %d, content = %s\n", c->nd->id, c->nd->content);
	  d = c->nd->child;
	  while (d)
	    {
	      printf("n3: id = %d, content = %s\n", d->nd->id, d->nd->content);
	      e = d->nd->child;
	      while (e)
		{
		  printf("n4: id = %d, content = %s\n", e->nd->id, e->nd->content);
		  f = e->nd->child;
		  while (f)
		    {
		      printf("n5: id = %d, content = %s\n", f->nd->id, f->nd->content);
		      f = f->next;
		    }
		  e = e->next;
		}
	      d = d->next;
	    }
	  c = c->next;
	}
    }
}


void	aff_tree(t_node *root)
{
  asc(root);
}



int	main(void)
{
  t_node	*root;
  t_token	*tok;
  t_token	*new;
  int		i;
  char	simple[13][150] = {" ls | ls | ls ; ls -la -h ; ls | ls",
			  "ls | ls > toto",
			  "ls | grep | ls && ls | ls | ls > toto && ls > toto; ls && titi",
			  "ls toto",
			  " ls ||  ls || ls ||",
			  "ls $VAR -la",
			  "ls > ls >",
			  "ls | ls |",
			  "|ls | ls",
			  "> ls ls | ls",
			  "ls > ls > ls",
			  "ls < ls > ls ",
			  "ls > ls < ls"};
  /* char	quote[17][50] = {"echo \"titi\"", */
  /* 			 "echo \"titi\" ", */
  /* 			 "echo \"titi toto\"", */
  /* 			 "echo \" \"", */
  /* 			 "\"\"", */
  /* 			 "echo 'titi'", */
  /* 			 "echo 'titi' ", */
  /* 			 "echo 'titi toto'", */
  /* 			 "echo '", */
  /* 			 "'", */
  /* 			 "echo `titi`", */
  /* 			 "echo `titi` ", */
  /* 			 "echo `titi toto`", */
  /* 			 "echo `", */
  /* 			 "``", */
  /* 			 "echo \"salut 'titi\"salut'", */
  /* 			 "\"salut'\"'salut'"}; */
  /* char	par[6][50] = {"ls && (titi titit tititit) || toto", */
  /* 		       "(titi); toto", */
  /* 		       "ls && (ll", */
  /* 		       "ls && (", */
  /* 		       "()", */
  /* 		       "toto )ksksk"}; */
  /* char	redir[13][50] = {"ls > toto", */
  /* 			 "ls >> toto", */
  /* 			 "ls > > toto", */
  /* 			 "ls < toto", */
  /* 			 "ls << toto", */
  /* 			 "ls < < toto", */
  /* 			 "ls >& toto", */
  /* 			 "ls >>& toto", */
  /* 			 "ls > & toto", */
  /* 			 "ls >> & toto", */
  /* 			 "ls < & toto", */
  /* 			 "ls << & toto", */
  /* 			 ">><<><><<>>>&<<>>&<"}; */
  /* char	history[7][50] = {"ls !kdkdkdk ldldld", */
  /* 			   "!!", */
  /* 			   "!llldl", */
  /* 			   "!", */
  /* 			   "ls !", */
  /* 			   "!!!!!", */
  /* 			   "!n500"}; */
  /* char	var[14][50] = {"ls $PATH", */
  /* 		      "$PATH", */
  /* 		      "$$", */
  /* 		      "$PAT$H", */
  /* 		      "$$$$$$$", */
  /* 		      "$", */
  /* 		      "$! toto", */
  /* 		      "$?", */
  /* 		      "${0", */
  /* 		      "$#name", */
  /* 		      "${?name}", */
  /* 		      "${#name}", */
  /* 		      " ${%number}", */
  /* 		      "ls$toto"}; */
  /* char	inib[5][50] = {"echo \\n", */
  /* 			"echo \\\\\\\\\\\\d", */
  /* 			"echo \\coucou", */
  /* 			"echo \"coucu\\ndd\"", */
  /* 			"\\\\\\\\d"}; */

  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||            SIMPLE           |||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */

  i = -1;
  root = NULL;
  while (++i < 13)
    {
      printf("#################################################\n####### %s\t\t###\n#################################################\n", simple[i]);
      tok = pars_tokenizer(simple[i]);
      my_rev_list(&tok);
      new = reconstruct_token(tok);
      aff_token(new);
      if (check_expression(new, &root) == TRUE)
	aff_tree(root);
    }
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||            QUOTE            |||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */

  /* i = -1; */
  /* while (++i < 17) */
  /*   { */
  /*     printf("#################################################\n####### %s\t\t###\n#################################################\n", quote[i]); */
  /*     tok = pars_tokenizer(quote[i]); */
  /*     my_rev_list(&tok); */
  /*     new = reconstruct_token(tok); */
  /*     aff_token(new); */
  /*   } */

  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||            PAR              |||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */

  /* i = -1; */
  /* while (++i < 6) */
  /*   { */
  /*     printf("#################################################\n####### %s\t\t###\n#################################################\n", par[i]); */
  /*     tok = pars_tokenizer(par[i]); */
  /*     my_rev_list(&tok); */
  /*     new = reconstruct_token(tok); */
  /*     aff_token(new); */
  /*   } */

  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||            REDIR            |||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */

  /* i = -1; */
  /* while (++i < 13) */
  /*   { */
  /*     printf("#################################################\n####### %s\t\t###\n#################################################\n", redir[i]); */
  /*     tok = pars_tokenizer(redir[i]); */
  /*     my_rev_list(&tok); */
  /*     new = reconstruct_token(tok); */
  /*     aff_token(new); */
  /*   } */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||            HISTORY          |||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */

  /* i = -1; */
  /* while (++i < 7) */
  /*   { */
  /*     printf("#################################################\n####### %s\t\t###\n#################################################\n", history[i]); */
  /*     tok = pars_tokenizer(history[i]); */
  /*     my_rev_list(&tok); */
  /*     new = reconstruct_token(tok); */
  /*     aff_token(new); */
  /*   } */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||            VARIABLES        |||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */

  /* i = -1; */
  /* while (++i < 14) */
  /*   { */
  /*     printf("#################################################\n####### %s\t\t###\n#################################################\n", var[i]); */
  /*     tok = pars_tokenizer(var[i]); */
  /*     my_rev_list(&tok); */
  /*     new = reconstruct_token(tok); */
  /*     aff_token(new); */
  /*   } */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||            INIBITEUR        |||||||||||||||||||||||||||\n"); */
  /* printf("||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); */

  /* i = -1; */
  /* while (++i < 5) */
  /*   { */
  /*     printf("#################################################\n####### %s\t\t###\n#################################################\n", inib[i]); */
  /*     tok = pars_tokenizer(inib[i]); */
  /*     my_rev_list(&tok); */
  /*     aff_token(tok); */
  /*     new = reconstruct_token(tok); */
  /*     aff_token(new); */
  /*   } */
  return (1);
}
