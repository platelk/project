/*
** main.c for main in /home/ozouf_h//42sh/srcs/parser/tokenizer
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Apr 10 15:42:41 2012 harold ozouf
** Last update Thu Apr 26 17:54:11 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"token.h"
#include	"my_rev_list.h"
#include	"reconstruct_token.h"
#include	"check_expression.h"

void	pipe(t_node *rt);
void	cmd(t_node *rt);
void	red(t_node *rt);
void	logi(t_node *rt);




int	main(void)
{
  t_node	*root;
  t_token	*tok;
  t_token	*new;
  int		i;
char	simple[47][550] = {
  "ls || ./lib &&  titi && toto",
  "> toto ls -la ./lib && ls | toto || cmd",
  "ls -la ./lib > toto",
  "< toto ls -la ./lib",
  "ls -la ./lib < toto",
  "echo 42sh",
  "echo ls | ./42sh",
  "cat << ^@",
  "cd -",
  "exit 0",
  "/bin/kill -11 0",
  "cd /root",
  "| ls",
  "^D",
  "unsetenv PATH; ls",
  "ls > test",
  "cat < test",
  "pwd >> test",
  "cat << EOF",
  "ls | wc -l",
  "cat < test | wc -c",
  "cat << EOF | less",
  "ls | wc -l >> test",
  "echo success | cat >> test >> test",
  "setenv USER toto | wc -l",
  "ls | less | wc -c",
  "echo hello | tr -d o | cat -e",
  "cat /etc/passwd | grep 42 | wc -l",
  "ls -lRa ../../ | cat | cat | cat | tr -s 42 | cat | cat | cat | wc -l",
  "badcommand && echo ne_doit_pas_safficher",
  "cd /root && echo ne_doit_pas_safficher",
  "ls && echo doit_safficher",
  "badcommand || echo doit_safficher",
  "/bin/kill -11 0 || echo doit_safficher",
  "ls && badcommad && echo ne_doit_pas_safficher",
  "badcommand || cd . || pwd",
  "badcommand || echo good_command && echo doit_safficher",
  "vbadvbadbad && ls || echo doit_safficher",
  "ls /root && echo yes || echo no && echo test && echo coucou",
  ";&&||",
  ";ls;",
  "       ls      |       cat     -e      ",
  "ls|cat",
  "        ",
  "<< toto cat > toto ; << EOF cat | sed s/toto/0/ > ma_note ; /bin/echo -n ma_note: ; < ma_note cat",
  "echo coucou >test; < test ls | cat -e| wc -c >> test && >> test echo success ;cat test",
  ""};

  /* char	quote[17][50] = {"echo \"titi\"", */
  /* 			 "echo \"titi\" ", */
  /* 			 "echo \"titi toto\"", */
  /* 			 "echo \" \"", */
  /* 			 "\"\"", */
  /* 			 "echo "titi"", */
  /* 			 "echo "titi" ", */
  /* 			 "echo "titi toto"", */
  /* 			 "echo "", */
  /* 			 """, */
  /* 			 "echo `titi`", */
  /* 			 "echo `titi` ", */
  /* 			 "echo `titi toto`", */
  /* 			 "echo `", */
  /* 			 "``", */
  /* 			 "echo \"salut "titi\"salut"", */
  /* 			 "\"salut"\""salut""}; */
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
  while (++i < 47)
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
