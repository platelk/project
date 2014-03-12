/*
** parse_ip.h for parse_ip.h in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  2 18:09:53 2012 harold ozouf
** Last update Tue May 29 20:05:10 2012 zoe phalippou
*/

#ifndef		__PARSE_IP_H__
# define	__PARSE_IP_H__

#include	"parse.h"

t_ip	*get_localhost(void);
int	parse_port(t_info *, char **, int *);
int	parse_ip(t_info *, char **, int *);
int	parse_port(t_info *, char **, int *);

#endif
