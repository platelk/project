/*
** token.h for token in /home/vink/projet/graph/xml/xml_inc
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Thu May  3 18:23:35 2012 kevin platel
** Last update Sat May  5 15:35:52 2012 kevin platel
*/

#ifndef __XML_TOKEN_H__
#define __XML_TOKEN_H__

typedef enum e_tok
  {
    TK_NULL,
    TK_EMPTY,
    TK_INV_NODE,
    TK_OPEN_NODE,
    TK_END_NODE,
    TK_SINGLE_NODE,
    TK_TERM_NODE
  } t_tok;

typedef struct s_token
{
  int	line;
  int	token;
  char	*content;
  char	*name;

  struct s_token	*next;
  struct s_token	*prev;
} t_token;

t_token	*xml_add_in_token_list(char *s, t_token *token, int line);
int	xml_get_token(char *s);
char	*xml_get_name_node(char *);

#endif
