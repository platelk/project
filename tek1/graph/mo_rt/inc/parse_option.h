/*
** parse_option.h for pare_option in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat May  5 20:55:34 2012 harold ozouf
** Last update Tue May 29 20:06:24 2012 zoe phalippou
*/

#ifndef		__PARSE_OPTION_H__
# define	__PARSE_OPTION_H__

#include	"parse.h"

int	parse_file(t_info *, char **, int *);
int	parse_mute(t_info *, char **, int *);
int	parse_verbose(t_info *, char **, int *);
int	parse_export(t_info *, char **, int *);
int	parse_thread(t_info *, char **, int *);

#endif
