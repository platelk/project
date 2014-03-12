/*
** unit_token_funct.c for unit_token_funct in /home/ozouf_h//42sh/src/parsing
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Mon Apr 16 16:38:09 2012 harold ozouf
** Last update Mon Apr 16 16:50:39 2012 harold ozouf
*/

int	main(void)
{
  t_token	*tok_dollar;
  t_token	*tok_pv;
  t_token	*tok_excla;
  char		*s_dollar;
  char		*s_pv;
  char		*s_excla;
  int		dollar;
  int		pv;
  int		excla;

  dollar = 0;
  tok = NULL;
  s_dollar = strdup("$dollar");
  s_pv = strdup(";pv");
  s_excla = strdup("!excla");
  if (is_a_dollar(&tok_dollar, &s_dollar) == TRUE)
    {
      if (tok_dollar)
	if (tok_dollar->id == DOLLARS && strcmp("$", tok_dollar->content))
	  if (strcmp("dollar", s_dollar))
	    dollar = 1;
    }
  if (is_a_dollar(&tok_pv, &s_pv) == TRUE)
    {
      if (tok_pv)
	if (tok_pv->id == PV && strcmp(";", tok_pv->content))
	  if (strcmp("dollar", s_pv))
	    pv = 1;
    }
  return (1);
}
