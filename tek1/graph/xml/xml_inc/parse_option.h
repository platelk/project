/*
** parse_option.h for pare_option in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat May  5 20:55:34 2012 harold ozouf
** Last update Sat May  5 20:56:58 2012 harold ozouf
*/

#ifndef		__PARSE_OPTION_H__
# define	__PARSE_OPTION_H__

#include	"parse.h"

int	parse_file(t_info *inf, char **argv, int *i);
int	parse_mute(t_info *inf, char **tab, int *i);
int	parse_verbose(t_info *inf, char **tab, int *i);
int	parse_export(t_info *inf, char **tab, int *i);
int	parse_thread(t_info *inf, char **tab, int *i);

#endif
