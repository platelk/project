/*
** server.h for server in /home/guiho_r/tek1/clustering/src/server
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Tue May  1 13:55:01 2012 ronan guiho
** Last update Mon May  7 17:19:46 2012 ronan guiho
*/

#ifndef __SERVER_H__
#define __SERVER_H__

#include "my.h"
#include "trame.h"
#include "../plage.h"
#include "client.h"

#define MAX_CLIENT	50
#define DELAY_PING	15

char			*server_client_receive_cut_trame(char *buffer, int i);
int			server_client_receive_is_valide(char *str);
void			*server_client_receive_plage(void *arg);
int			server_client_receive_action(t_client *client, \
						     char *buffer);
int			server_client_receive_treatement(t_client *client, \
							 t_trame **trame);
int			server_client_receive_remove(t_trame **list, \
						     t_trame *tmp);
int			server_client_receive_analize(t_trame **list_trame, \
						      char *buffer);
int			server_ping_flood(t_client *tmp);
int			server_distribution_send();
int			server_distribution_atribution(t_plage *plage);
int			server_client_core(t_client *client);
t_client		*server_client_id(int id);
int			server_client_count();
t_plage			*server_distribution_plage_calcul();
int			server_distribution_start();
int			server_client_connected(t_client **list, \
						SOCKET ssock);
int			server_management_start();
int			server_ping_start();
int			server_ping_check_recv();
int			server_client_remove(t_client *client);
int			server_listen(SOCKET ssock);
int			server_ping_raz();
void			server_close(int seg);
t_client		*server_client_create();
void			*server_client_receive(void *arg);
char			*server_int_to_str(int value);
struct sockaddr_in	*server_sockaddr_create(int port);
int			server_client_add(t_client **list, t_client *client);
void			server_client_display(t_client *list);
int			server_distribution_start();

#endif
