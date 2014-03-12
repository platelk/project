/*
** signial.c for signal in /home/vink/projet/sys_unix/42sh/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Apr 28 13:12:04 2012 kevin platel
** Last update Mon Apr 30 11:54:00 2012 ronan guiho
*/

#include	<stdio.h>
#include	<signal.h>

#include	"global.h"

t_global	global;

void	signal_sigint(int seg)
{
  (void)seg;
  my_putchar('\n');
  my_putstr(global.prompt);
}

void	start_signal(void)
{
  signal(SIGINT, SIG_DFL);
  signal(SIGTSTP, SIG_DFL);
  signal(SIGKILL, SIG_DFL);
  signal(SIGQUIT, SIG_DFL);
}

void	stop_signal(void)
{
  signal(SIGINT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGKILL, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
}
