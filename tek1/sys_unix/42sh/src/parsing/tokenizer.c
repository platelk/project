/*
** tokenizer.c for tokenizer in /home/ozouf_h//42sh/include
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Mon Apr  9 15:42:01 2012 harold ozouf
** Last update Fri May 18 14:19:47 2012 harold ozouf
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>

#include	"token_funct.h"
#include	"token.h"
#include	"xsys.h"

f_token	*init_ptr_funct_token(void)
{
  f_token	*tab;

  if ((tab = xmalloc(sizeof(*tab) * 13)) == NULL)
    return (NULL);
  tab[0] = &is_a_spacer;
  tab[1] = &is_a_dollar;
  tab[2] = &is_a_inibited_char;
  tab[3] = &is_an_oper_cond;
  tab[4] = &is_a_esp;
  tab[5] = &is_a_red_d;
  tab[6] = &is_a_red_s;
  tab[7] = &is_a_par;
  tab[8] = &is_a_pv;
  tab[9] = &is_a_quote;
  tab[10] = &is_an_excla;
  tab[11] = &is_a_word;
  tab[12] = NULL;
  return (tab);
}

t_token	*pars_tokenizer(char *str)
{
  f_token	*tab;
  t_token	*tok;
  int		i;
  int		res;
  int		done;

  tok = NULL;
  done = 1;
  if ((tab = init_ptr_funct_token()) == NULL)
    return (NULL);
  while (done)
    {
      i = -1;
      res = FALSE;
      while (++i < 12 && res == FALSE)
	if ((res = tab[i](&tok, &str)) == ERROR)
	  return (NULL);
      if (res == FALSE)
	done = 0;
    }
  (tab) ? free(tab) : (tab = NULL);
  return (tok);
}

int	add_token(t_token **tok, t_t_list id, char *c, t_t_spec spec)
{
  t_token	*new;

  if ((new = xmalloc(sizeof(*new))) != NULL)
    {
      new->content = strdup(c);
      new->id = id;
      new->spec = spec;
      new->next = *tok;
      *tok = new;
      return (EXIT_SUCCESS);
  }
  return (EXIT_FAILURE);
}

void	aff_token(t_token *tok)
{
  printf("affichage\n");
  while (tok != NULL)
    {
      printf("__________________________________________________________\n");
      printf("| %d\t|\t%s\t|\n", tok->id, tok->content);
      printf("|_________________________________________________________\n");
      tok = tok->next;
    }
  if (tok == NULL)
    printf("coucou\n");
  printf("end\n");
}
