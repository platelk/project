/*
** xfnt.h for xfnt in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Tue Feb 14 10:20:35 2012 harold ozouf
** Last update Wed Feb 15 22:04:14 2012 harold ozouf
*/

#ifndef		XFNT_H__
# define	XFNT_H__

void    xexit(char *str);
void	*xmalloc(int size);
void	*xrealloc(char *str, int size);
int	xopen(char *str, int flags);
void	xerror(char *name, char *msg);

#endif
