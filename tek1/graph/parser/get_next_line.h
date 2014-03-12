/*
** get_next_line.h for get_next_line in /home/leprov_a//afs/current/warning/get_next_line
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Feb  2 11:04:30 2012 alexis leprovost
** Last update Mon Apr 23 10:48:48 2012 alexis leprovost
*/

#ifndef	__GET_NEXT_LINE_H__
#define	__GET_NEXT_LINE_H__

typedef struct	s_line
{
  char	letter;
  int	indice;
  int	status;
  struct s_line	*next;
  struct s_line *prev;
} t_line;

char	*get_next_line(const int fd);

#endif
