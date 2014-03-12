/*
** exec_com.c for exec_com in /home/vink/projet/sys_unix/minishell2/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Feb 13 22:36:08 2012 kevin platel
** Last update Fri Mar  2 11:17:54 2012 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "my.h"
#include "minishell.h"
#include "env.h"
#include "pwd.h"
#include "cmd.h"

int	gest_pipe(t_cmd *cmd)
{
  if (cmd && cmd->prev && cmd->prev->sep == PIPE)
    {
      if ((close(cmd->prev->pipefd[1])) < 0)
	{
	  write(2, "Error close1\n", my_strlen("Error close1\n"));
	  exit(0);
	}
      else if (dup2(cmd->prev->pipefd[0], 0) < 0)
	{
	  write(2, "Error dup0\n", my_strlen("Error dup0\n"));
	  exit(0);
	}
    }
  if (cmd && cmd->sep == PIPE)
    {
      if ((close(cmd->pipefd[0])) < 0)
	{
	  write(2, "Error close\n", my_strlen("Error close\n"));
	  exit(0);
	}
      else if (dup2(cmd->pipefd[1], 1) < 0)
	{
	  write(2, "Error dup\n", my_strlen("Error dup\n"));
	  exit(0);
	}
    }
  return (0);
}

t_cmd	*gest_red_right(t_cmd *cmd)
{
  int	fd;
  char	*file;

  file = NULL;
  if (cmd && cmd->next)
    file = my_strtok(cmd->next->cmd, " \t")[0];
  else
    return (NULL);
  if (cmd->sep == RED_RIGHT)
    fd = open(file, O_WRONLY | O_CREAT | O_TRUNC,
	      S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  else if (cmd->sep == RED2_RIGHT)
    fd = open(file, O_WRONLY | O_CREAT | O_APPEND,
	      S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
  if (fd == -1)
    {
      write(2, "Error can't open/creat file\n", 28);
      return (NULL);
    }
  if (dup2(fd, 1) == -1)
    {
      write(2, "Error dup\n", 10);
      return (NULL);
    }
  return (cmd);
}

t_cmd	*gest_left_right(t_cmd *cmd)
{
  int	fd;
  char	**file;

  file = NULL;
  fd = -1;
  if (cmd && cmd->next)
    file = my_strtok(cmd->next->cmd, " \t");
  if (cmd->sep == RED_LEFT)
    fd = open(file[0], O_RDONLY);
  if (fd == -1)
    {
      write(2, "Error can't open/creat file\n", 28);
      return (NULL);
    }
  if (dup2(fd, 0) == -1)
    {
      write(2, "Error dup\n", 10);
      return (NULL);
    }
  return (cmd);
}

int	exec_comd(t_cmd *cmd, t_env **envp, t_pwd **my_pwd)
{
  int	pid;

  pid = 0;
  while (cmd)
    {
      if (cmd->sep != 0 || builtin(cmd->cmd) == 0)
	{
	  pid = fork();
	  if ((pid) == 0)
	    {
	      if ((cmd->sep == PIPE || (cmd->prev && cmd->prev->sep == PIPE)))
		gest_pipe(cmd);
	      if (cmd->next && cmd->sep == RED_RIGHT || cmd->sep == RED2_RIGHT)
		cmd = gest_red_right(cmd);
	      if (cmd->next && cmd->sep == RED_LEFT || cmd->sep == RED2_LEFT)
		cmd = gest_left_right(cmd);
	      if (cmd && !is_builtin(cmd->cmd, envp, my_pwd))
		exec_cmd(cmd->cmd, envp);
	      exit(0);
	    }
	  else
	    if (cmd && cmd->prev && cmd->prev->sep == PIPE)
	      close(cmd->prev->pipefd[1]);
	}
      else
	is_builtin(cmd->cmd, envp, my_pwd);
      cmd = cmd->next;
      if (cmd && cmd->prev && 
	  (cmd->prev->sep != PIPE || cmd->prev->sep != 0))
	{
	  cmd = cmd->next;
	}
    }
  waitpid(pid, NULL, 0);
  error_sig(pid);
  return (0);
}
