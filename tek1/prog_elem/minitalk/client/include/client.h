/*
** client.h for client in /home/platel_k/projet/prog_elem/minitalk/source/client/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Jan 16 12:55:41 2012 kevin platel
** Last update Tue Mar 13 16:53:29 2012 kevin platel
*/

#ifndef	__CLIENT_H__
#define __CLIENT_H__

typedef union u_nb
{
  int	nb;
  unsigned char	tab[4];
} t_nb;

void	send_signial(unsigned char buff, int pid, int mod);
void	send_int(int pid, int n);
void	sig(int signal);

#endif
