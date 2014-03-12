/*
** signial.c for signal in /home/vink/projet/sys_unix/42sh/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sat Apr 28 13:12:04 2012 kevin platel
** Last update Thu May 17 16:17:11 2012 alexis leprovost
*/

#include	<stdio.h>
#include	<signal.h>

#include	"edit.h"
#include	"my.h"
#include	"global.h"

t_global	global;

void	signal_sigint(int seg)
{
  (void)seg;
  my_putchar('\n');
  termcap_prompt(global.prompt, (global.dom[X] - 1));
  global.ctrlc = 1;
}

void	start_signal(void)
{
  signal(SIGINT, SIG_DFL);
  signal(SIGKILL, SIG_DFL);
  signal(SIGQUIT, SIG_DFL);
  signal(SIGTTOU, SIG_IGN);
  signal(SIGTERM, SIG_DFL);
  signal(SIGTSTP, SIG_IGN);
}

void	stop_signal(void)
{
  signal(SIGINT, &signal_sigint);
  signal(SIGTERM, SIG_IGN);
  signal(SIGKILL, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
}
