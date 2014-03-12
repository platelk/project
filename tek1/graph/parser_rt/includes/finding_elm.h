/*
** finding_elm.h for finding_elm in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 21:12:00 2012 harold ozouf
** Last update Thu Apr 26 13:09:03 2012 kevin platel
*/

#ifndef		FINDING_ELM_H__
# define	FINDING_ELM_H__

#include	"node.h"

char	*get_value(t_node *node);
char	*get_next_name(char **path);
t_node	*get_node(char *path, t_node *src);
t_node	*is_in_list(char *name, t_node *tmp);

#endif
