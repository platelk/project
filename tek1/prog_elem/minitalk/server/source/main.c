/*
** main.c for main] in /home/platel_k/projet/prog_elem/minitalk/source/client/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Jan 16 12:57:25 2012 kevin platel
** Last update Sun Mar 18 14:59:25 2012 kevin platel
*/

#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "my.h"

typedef struct u_nb
{
  int	pid;
  int	paq;
  int	n;
  int	i;
} t_nb;

t_nb	pid_client;

void	get_pid_client(unsigned char character)
{
  if (character < 254 && pid_client.pid == 0 && pid_client.paq <= 4)
    {
      pid_client.n += character;
      pid_client.paq++;
      if (pid_client.paq < 4)
	pid_client.n = pid_client.n << 8;
    }
  if (pid_client.paq >= 4)
    {
      my_printf("\nPid du client => %d [%X]\n", pid_client.n, pid_client.n);
      pid_client.pid = pid_client.n;
      pid_client.n = 0;
      pid_client.paq = 0;
    }
  else
    my_putchar(character);
}

void	get_signal(unsigned char *character, int *nb_bit, int signal)
{
  if (signal == 10)
    {
      (*character) = ((*character) | 1);
      if ((*nb_bit) < 7)
	(*character) = (*character) << 1;
      (*nb_bit)++;
    }
  else if (signal == 12)
    {
      (*character) = ((*character) | 0);
      if ((*nb_bit) < 7)
	(*character) = (*character) << 1;
      (*nb_bit)++;
    }
  pid_client.i = 0;
}

void	read_signal(int signal)
{
  static unsigned char	character;
  static int	nb_bit;

  get_signal(&character, &nb_bit, signal);
  if (nb_bit >= 8)
    {
      if (character == 255)
	{
	  pid_client.pid = 0;
	  pid_client.paq = 0;
	  pid_client.n = 0;
	  pid_client.i = 0;
	}
      else
	get_pid_client(character);
      nb_bit = 0;
      character = '\0';
    }
  if (pid_client.pid != 0)
    kill(pid_client.pid, SIGUSR1);
}

int	main()
{
  pid_client.pid = 0;
  pid_client.paq = 0;
  pid_client.n = 0;
  pid_client.i = 0;
  my_printf("Mon pid est : %d\n", getpid());
  signal(SIGUSR1, &read_signal);
  signal(SIGUSR2, &read_signal);
  while (42)
    {
      if (pid_client.pid != 0)
	(pid_client.i) += 1;
      if (pid_client.i > 10)
	kill(pid_client.pid, SIGUSR1);
      usleep(1);
    }
  return (0);
}
