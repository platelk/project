/*
** get_next_line.h for get_next_lin in /home/platel_k/projet/get_next_line
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Nov 14 14:01:31 2011 kevin platel
** Last update Sat Dec 31 01:26:45 2011 kevin platel
*/

#ifndef __GET_NEXT_LINE__
#define __GET_NEXT_LINE__

#define BUFFER_SIZE	(20)
#define READ_SIZE	(50)

char		*get_next_line(const int fd, t_env *env, t_pwd *my_pwd);

#endif
