/*
** gest_cmd.c for gest_cmd in /home/platel_k/projet/sys_unix/minishell2/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Feb  1 14:34:53 2012 kevin platel
** Last update Wed Feb 29 16:01:37 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"
#include "cmd.h"

int	treat_cmd(char *buffer, t_env **envp, t_pwd **pwd)
{
  char	**tab;
  int	i;
  t_cmd	*cmd;

  tab = my_strtok(buffer, ";");
  i = 0;
  cmd = NULL;
  while (tab[i])
    {
      cmd = analyse_cmd(tab[i]);
      exec_comd(cmd, envp, pwd);
      i++;
    }
  tab = freewordtab(tab);
  if (tab != NULL)
    free(tab);
  return (1);
}

int	gest_cmd(t_env *envp, t_pwd *my_pwd)
{
  char	*buffer;
  int	end;

  end = 1;
  while (end)
    {
      buffer = show_prompt(envp, my_pwd);
      if (buffer != NULL)
	{
	  end = treat_cmd(buffer, &envp, &my_pwd);
	  if (buffer != NULL)
	    free(buffer);
	}
    }
  quit(envp, my_pwd);
  return (0);
}
