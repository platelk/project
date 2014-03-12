/*
** term_mode.c for term_mode in /home/platel_k/projet/sys_unix/myselect/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Jan 11 15:10:30 2012 kevin platel
** Last update Wed Apr 25 09:43:58 2012 kevin platel
*/

#include <stdlib.h>
#include <termios.h>
#include "my.h"
#include "minishell.h"

char *tgoto(const char *cap, int col, int row);
int	put_c(int cap);

int	raw_mode(int mode)
{
  struct	termios	t;

  if (tcgetattr(0, &t) < 0)
    {
      my_printf("Error, terminal doesn't exist\n");
      return (ERROR);
    }
  if (mode == SET)
    {
      t.c_lflag &= ~ICANON;
      t.c_cc[VMIN] = 1;
      t.c_cc[VTIME] = 0;
    }
  else if (mode == UNSET)
    t.c_lflag |= ICANON;
  else
    return (ERROR);
  tcsetattr(0, TCSANOW, &t);
  return (0);
}

int	echo_mode(int mode)
{
  struct	termios	t;

  if (tcgetattr(0, &t) < 0)
    {
      my_printf("Error, terminal doesn't exist\n");
      return (ERROR);
    }
  if (mode == SET)
    t.c_lflag |= ECHO;
  else if (mode == UNSET)
    t.c_lflag &= ~ECHO;
  else
    {
      my_printf("Error, mode need value 1 or 0\n");
      return (ERROR);
    }
  if (tcsetattr(0, TCSANOW, &t) < 0)
    {
      my_printf("Error, can't set terminal attribute\n");
      return (ERROR);
    }
  return (0);
}

int	visible_cursor(int mode)
{
  if (mode == SET)
    use_termcap("ve");
  else if (mode == UNSET)
    use_termcap("vi");
  else
    {
      my_printf("Error, can't set terminal attribute\n");
      return (ERROR);
    }
  return (0);
}

int	mouv_curs(int x, int y)
{
  char	*cap;

  cap = tgetstr("cm", NULL);
  cap = tgotod(cap, y, x);
  if (tputs(cap, 1, &put_c) == -1)
    return (ERROR);
  return (0);
}

int	screen_clean(void)
{
  char	*cap;

  cap = tgetstr("cl", NULL);
  if (tputs(cap, 1, &put_c) == -1)
    return (ERROR);
  return (0);
}
