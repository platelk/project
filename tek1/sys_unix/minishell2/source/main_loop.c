/*
** main_loop.c for main_loop in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Dec 13 08:42:49 2011 kevin platel
** Last update Wed Feb 29 16:09:25 2012 kevin platel
*/

#include <sys/types.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"

char	*show_prompt(t_env *env, t_pwd *my_pwd)
{
  char	*buffer;

  show_dir(my_pwd);
  my_printf(" $>");
  if (raw_mode(SET) == ERROR)
    buffer = get_next_line(0, env, my_pwd);
  else
    {
      echo_mode(UNSET);
      buffer = get_cmd();
    }
  if (raw_mode(UNSET) == ERROR)
    return (NULL);
  if (echo_mode(SET) == ERROR)
    return (NULL);
  return (buffer);
}

void	stop_signal(void)
{
  signal(SIGINT, SIG_IGN);
  signal(SIGTSTP, SIG_IGN);
  signal(SIGKILL, SIG_IGN);
  signal(SIGQUIT, SIG_IGN);
}

void	error_sig(int sig)
{
  int	nb_sig;

  if (WIFSIGNALED(sig) > 0)
    {
      nb_sig = WTERMSIG(sig);
      if (nb_sig == SIGSEGV)
	my_printf("Error : Segmentation fault.\n");
      else if (nb_sig == SIGFPE)
	my_printf("Error : Floating point exception.\n");
      else if (nb_sig == SIGILL)
	my_printf("Error : Illegal instruction.\n");
      else if (nb_sig == SIGBUS)
	my_printf("Error : Bus error.\n");
    }
}

void	main_loop(t_env *env, t_pwd *my_pwd)
{
  int	ret;
  char	*buffer;
  int	finish;

  finish = 1;
  while (finish)
    {
      buffer = show_prompt(env, my_pwd);
      if (is_builtin(buffer, &env, &my_pwd) != 1)
	{
	  ret = fork();
	  if (ret == 0)
	    {
	      signal(SIGINT, SIG_DFL);
	      exec(env, buffer);
	      exit(0);
	      finish = 0;
	    }
	  else
	    wait(&ret);
	  error_sig(ret);
	}
      free(buffer);
    }
  quit(env, my_pwd);
}
