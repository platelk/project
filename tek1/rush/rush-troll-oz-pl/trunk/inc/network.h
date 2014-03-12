/*
** network.h for network.h in /home/vink/projet/rush/rush-troll-oz-pl/trunk
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Jun  7 11:52:03 2012 kevin platel
** Last update Fri Jun  8 08:27:03 2012 kevin platel
*/

#ifndef	__NETWORK_H__
#define	__NETWORK_H__

#include "teuquain.h"

t_param *net_get_param(t_param *param);
t_attak	*net_get_attak(char *buffer, t_attak *attak);
int	add_attack(t_file_attak **file, char *buffer, int nb_door);
int	*create_door(int nb_door);

#endif
