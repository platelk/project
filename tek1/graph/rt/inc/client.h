/*
** client.h for client in /home/guiho_r/tek1/clustering/src/client
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 11:08:14 2012 ronan guiho
** Last update Fri Jun  1 10:39:08 2012 ronan guiho
*/

#ifndef __CLIENT_H__
#define __CLIENT_H__

#include <stdio.h>
#include <fcntl.h>
#include <pthread.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/time.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "global.h"
#include "plage.h"
#include "color.h"
#include "my_strtok.h"

#define CLIENT_THREAD	 4
#define INVALID_SOCKET	-1
#define SOCKET_ERROR	-1

typedef int SOCKET;

typedef struct		s_client
{
  int			id;
  SOCKET		sock;
  struct sockaddr_in	*csin;
  int			ping;
  int			size_csin;
  int			latence;
  int			core;
  int			status;
  t_plage		*plage;
  struct timeval	tv;
  struct s_client	*next;
} t_client;

int			client_core();
char			*client_endtrame(char *);
void			*client_calculation(void *);
int			client_calculation_send(char *, int, int);
char			*client_calculation_header(int, int, int);
int			client_listen();
void			client_close(int);
char		        *client_calculation_buffer(t_color *);
char			*client_calculation_buffer_tab(char **);
int			client_main(char *, int);
struct sockaddr_in	*client_sockaddr_create(char *, int);

#endif
