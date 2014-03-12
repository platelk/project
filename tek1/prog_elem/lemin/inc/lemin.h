/*
** lemin.h for lemin in /home/guiho_r/tek1/lemin/src/parser
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Wed Apr  4 11:01:33 2012 ronan guiho
** Last update Wed Apr 11 13:35:57 2012 ronan guiho
*/

#ifndef __LEMIN_H__
#define __LEMIN_H__

#include <stdarg.h>

#define SIZE_BUFFER	1000000
#define DELIM_BUFFER	'\n'

#define	DELIM_ROOM	' '

#define DELIM_LINK	'-'

#include	"my.h"
#include	"ant.h"
#include	"move.h"
#include	"room.h"
#include	"global.h"
#include	"weighting.h"
#include	"print.h"
#include	"path_find.h"

t_glob		*parser_main();
int             my_printf(const char *format, ...);
void		parser_free_tab(char **tab);
int		parser_size_tab(char **tab);
int		parser_size_list(t_room *room);
t_ant		**parser_init_ant(t_glob *global);
int		parser_room_analize(t_room *list);
int		parser_check_if_link(char *buffer);
struct s_room	**parser_malloc_link_tab(t_room *list);
int		parser_check_if_state(char *buffer, int i);
int		parser_room(t_glob *global, char **tab_parser,
			    int indice);
int		parser_link(t_room *list, char **tab, int i);
t_room		*parser_return_start_end(t_room *list, int flag);

#endif
