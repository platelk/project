/*
** balise.h for balise in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Feb 14 16:16:55 2012 harold ozouf
** Last update Wed Feb 15 15:48:16 2012 harold ozouf
*/

#ifndef		BALISE_H__
# define	BALISE_H__

# define	MARKER_LEN	25
# define	MARKER_PRE	'<'
# define	MARKER_SUF	'>'
# define	MARKER_END	'/'

int	get_next_marker(char **xml, char **name);
int	get_end_marker(char **xml, char *name);
int	delete_marker(char **xml, char *name);

#endif
