/*
** xml_token.h for xml in /home/vink/projet/graph/rt/src/moebus
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jun  3 16:33:21 2012 kevin platel
** Last update Sun Jun  3 16:33:22 2012 kevin platel
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

t_token		*xml_add_in_token_list(char *, t_token *, int);
int		xml_get_token(char *);
char		*xml_get_name_node(char *);

#endif
