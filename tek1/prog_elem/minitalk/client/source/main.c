/*
** main.c for main] in /home/platel_k/projet/prog_elem/minitalk/source/client/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Jan 16 12:57:25 2012 kevin platel
** Last update Sun Mar 18 15:02:07 2012 kevin platel
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "client.h"
#include "my.h"

void	sig(int signal)
{
  signal = signal;
}

void	send_int(int pid, int n)
{
  t_nb	nb;
  int	i;

  i = 0;
  nb.nb = n;
  send_signial(255, pid, 1);
  while (i < 4)
    {
      send_signial(nb.tab[3 - i], pid, 1);
      i++;
    }
  usleep(50);
}

void	send_signial(unsigned char buff, int pid, int mod)
{
  unsigned char	cursor;
  unsigned char	i;

  i = 0;
  cursor = 128;
  while (i < 8)
    {
      if ((buff & cursor) == cursor)
	kill(pid, SIGUSR1);
      else
	kill(pid, SIGUSR2);
      cursor = cursor >> 1;
      i++;
      if (mod == 0)
	pause();
      else
	usleep(300);
    }
}

int	main(int ac, char **av)
{
  int	sev_pid;
  int	i;

  i = 0;
  signal(SIGUSR1, sig);
  signal(SIGUSR2, sig);
  if (ac < 2)
    {
      my_printf("Give the PID of server\n");
      return (0);
    }
  if (ac < 3)
    {
      my_printf("Give the message\n");
      return (0);
    }
  sev_pid = my_getnbr(av[1]);
  send_int(sev_pid, getpid());
  while (av[2][i] != 0)
    {
      send_signial(av[2][i], sev_pid, 0);
      i++;
    }
  return (0);
}
