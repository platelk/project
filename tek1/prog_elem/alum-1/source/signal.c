/*
** signal.c for signal in /home/platel_k/projet/sys_unix/myselect
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Fri Jan 13 10:52:33 2012 kevin platel
** Last update Fri Jan 13 17:14:05 2012 kevin platel
*/

#include <stdlib.h>
#include <signal.h>
#include <termios.h>
#include "myselect.h"

void	winch_signal(int signal)
{
  struct	termios t;

  if (signal == SIGWINCH)
    {
      if (tcgetattr(0, &t) >= 0)
	{
	  t.c_lflag &= ~ICANON;
	  t.c_cc[VMIN] = 0;
	  t.c_cc[VTIME] = 1;
	  tcsetattr(0, TCSANOW, &t);
	}
    }
}

int	disable_signal(void)
{
  if (signal(SIGINT, &quit_signal) == SIG_ERR)
    return (ERROR);
  if (signal(SIGWINCH, &winch_signal) == SIG_ERR)
    return (ERROR);
  return (0);
}
