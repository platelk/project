/*
** token.h for token in /home/ozouf_h//42sh/include
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Mon Apr  9 15:32:53 2012 harold ozouf
** Last update Thu Apr 19 10:40:55 2012 harold ozouf
*/

#ifndef		__TOKEN_H__
#define		__TOKEN_H__

typedef	enum	e_token
  {
    PV = 0,
    AND,
    OR,
    ESP,
    S_RED_RIGHT,
    D_RED_RIGHT,
    S_RED_LEFT,
    D_RED_LEFT,
    PIPE,
    DOLLARS,
    EXCLA,
    WORD,
    S_RED_RIGHT_ERR,
    D_RED_RIGHT_ERR,
    INIBIT,
    SPACE,
    TAB,
    CMD,
    ARG,
    QUOTE,
    UNKNOW,
  } t_t_list;

typedef	enum	e_spec
  {
    S_QUOTE,
    D_QUOTE,
    B_QUOTE,
    PAR,
    S_PAR,
    E_PAR,
    HISTORY,
    VARIABLES,
    NONE
  } t_t_spec;

typedef	enum	e_bool
  {
    TRUE,
    FALSE,
    ERROR
  } t_bool;

typedef	struct	s_token
{
  t_t_list		id;
  t_t_spec		spec;
  char			*content;
  struct s_token	*next;
} t_token;

typedef        t_bool   (*f_token)(t_token **tok, char **str);
typedef        t_bool   (*f_regroup)(t_token **, t_token **);

t_token		*pars_tokenizer(char *str);
void		add_token(t_token **tok, t_t_list id, char *c,t_t_spec spec);
f_token		*init_ptr_funct_token(void);
void		aff_token(t_token *tok);

#endif
