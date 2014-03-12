/*
** trame.h for server in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun May  6 19:32:21 2012 ronan guiho
** Last update Mon May  7 09:40:30 2012 ronan guiho
*/

#ifndef __TRAME_H__
#define __TRAME_H__

#include "client.h"

typedef struct	 s_trame
{
  int		 size;
  char		 *buffer;
  t_client	 *client;
  struct s_trame *next;
} t_trame;

#endif
