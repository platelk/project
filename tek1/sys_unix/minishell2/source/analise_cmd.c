/*
** analise_cmd.c for analyse_cmd in /home/platel_k/projet/sys_unix/minishell2/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Wed Feb  1 15:15:38 2012 kevin platel
** Last update Wed Feb 29 15:27:50 2012 kevin platel
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
#include "cmd.h"

int	exec_cmd(char *cmd, t_env **envp)
{
  signal(SIGINT, SIG_DFL);
  exec((*envp), cmd);
  free(cmd);
  exit(0);
  return (0);
}

int	my_is_operand(char *str)
{
  if (my_strcmp(str, STR_PIPE) == 0)
    return (PIPE);
  if (my_strcmp(str, STR_RED_RIGHT) == 0)
    return (RED_RIGHT);
  if (my_strcmp(str, STR_RED2_RIGHT) == 0)
    return (RED2_RIGHT);
  if (my_strcmp(str, STR_RED_LEFT) == 0)
    return (RED_LEFT);
  if (my_strcmp(str, STR_RED2_LEFT) == 0)
    return (RED2_LEFT);
  return (0);
}

t_cmd	*aply_operand(char *cmd, int operand, t_cmd *command)
{
  t_cmd	*new;

  new = malloc(sizeof(*new));
  while (command && command->next != NULL)
    command = command->next;
  if (new == NULL)
    return (NULL);
  new->cmd = my_strdup(cmd);
  new->sep = operand;
  if (operand == PIPE)
    if (pipe(new->pipefd) < 0)
      {
	write(2, "Error Pipe\n", my_strlen("Error Pipe\n"));
	return (NULL);
      }
  new->next = NULL;
  new->prev = command;
  if (command != NULL)
    command->next = new;
  while (new && new->prev != NULL)
    new = new->prev;
  return (new);
}

t_cmd	 *analyse_cmd(char *cmd)
{
  int	i;
  char	**tab;
  char	*comd;
  t_cmd	*command;

  i = 0;
  comd = NULL;
  tab = my_strtok(cmd, " ");
  command = NULL;
  while (tab[i])
    {
      while (tab[i] && my_is_operand(tab[i]) == 0)
	{
	  comd = my_strmcat(comd, tab[i]);
	  comd = my_strmcat(comd, " ");
	  i++;
	}
      command = aply_operand(comd, my_is_operand(tab[i]), command);
      if (comd != NULL)
	free(comd);
      comd = NULL;
      tab[i] != NULL ? (i++) : (i = i);
    }
  if (tab != NULL)
    freewordtab(tab);
  return (command);
}
