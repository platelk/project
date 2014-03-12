/*
** server.h for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 13:55:01 2012 ronan guiho
** Last update Sun Jun  3 18:15:08 2012 ronan guiho
*/

#ifndef __SERVER_H__
#define __SERVER_H__

#include "my.h"
#include "trame.h"
#include "plage.h"
#include "client.h"
#include "my_strtok.h"

#define MAX_CLIENT	50
#define DELAY_PING	180

char			*server_client_receive_cut_trame(char *);
int			server_client_receive_is_valide(char *);
void			*server_client_receive_plage(void *);
int			server_client_receive_action(t_client *, char *);
int			server_client_receive_treatement(t_client *,
							 t_trame **);
int			server_client_receive_remove(t_trame **, t_trame *);
int			server_client_receive_analize(t_trame **, char *);
int			server_ping_flood(t_client *);
int			server_distribution_send();
int			server_distribution_atribution(t_plage *);
int			server_client_core(t_client *);
t_client		*server_client_id(int);
int			server_client_count();
t_plage			*server_distribution_plage_calcul();
int			server_distribution_start();
int			server_client_connected(t_client **, SOCKET);
int			server_management_start();
int			server_ping_start();
int			server_ping_check_recv();
int			server_client_remove(t_client *);
int			server_listen(SOCKET);
int			server_ping_raz();
void			server_close(int);
t_client		*server_client_create();
void			*server_client_receive(void *);
char			*server_int_to_str(int);
struct sockaddr_in	*server_sockaddr_create(int);
int			server_client_add(t_client **, t_client *);
void			server_client_display(t_client *);
int			server_distribution_start();
int                     server_main(int);

#endif
