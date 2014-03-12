/*
** hex.h for hex in /home/leprov_a//depot/lemin/bonus/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr  2 14:29:03 2012 alexis leprovost
** Last update Wed Apr 11 16:11:50 2012 alexis leprovost
*/

#ifndef __HEX_H__
#define __HEX_H__

#include	"ant.h"
#include	"room.h"
#include	"move.h"
#include	"my.h"
#include	"image.h"

#define	X_WIN	1000
#define	Y_WIN	1000
#define	STEP	10

#define SIZE_BUFFER     1000000

#define DELIM_BUFFER    '\n'
#define DELIM_ROOM      ' '
#define DELIM_LINK      '-'

typedef enum e_bool
{
  TRUE,
  FALSE
} t_bool;

typedef struct s_glob
{
  t_room	*room;
  t_move	*move;
  t_image	*image;
    /*    t_sound	*sound;*/
  t_ant	**ant;
  SDL_Surface	*window;
  int	nb_ant;
} t_glob;

char		**get_world(t_room *room);
int		convert_room(t_room *room);
int		modif_pos(int *x, int *y, t_room *tmp);
char		**spawn_room(t_room *room, char **map);
t_room		*get_room(t_room *room, const int flag, const int aim);
int		get_coeff(t_room *room, const int flag, const int max);
char		**init_world(void);
char		**get_world(t_room *room);
t_glob          *parser_main();
int             my_printf(const char *format, ...);
void            parser_free_tab(char **tab);
int             parser_size_tab(char **tab);
int             parser_size_list(t_room *room);
t_ant           **parser_init_ant(t_glob *global);
int             parser_room_analize(t_room *list);
int             parser_check_if_link(char *buffer);
struct s_room   **parser_malloc_link_tab(t_room *list);
int             parser_check_if_state(char *buffer, int i);
int             parser_room(t_glob *global, char **tab_parser,
                            int indice);
int             parser_link(t_room *list, char **tab, int i);
t_room          *parser_return_start_end(t_room *list, int flag);

#endif
