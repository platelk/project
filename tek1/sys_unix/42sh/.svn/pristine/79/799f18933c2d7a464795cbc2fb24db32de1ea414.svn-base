/*
** exec_signal.c for exec_stack in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 19 11:31:03 2012 ronan guiho
** Last update Sat May 12 17:01:54 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int	exec_signal_other(int signal)
{
  if (signal == SIGSYS)
    {
      fprintf(stderr, "Bad argument to routine.\n");
      return (EXIT_FAILURE);
    }
  else if (signal == SIGTRAP)
    {
      fprintf(stderr, "Trace/breakpoint trap.\n");
      return (EXIT_FAILURE);
    }
  else if (signal == SIGIOT)
    {
      fprintf(stderr, "IOT trap.\n");
      return (EXIT_FAILURE);
    }
  else if (signal == SIGQUIT)
    {
      fprintf(stderr, "Quit from keyboard.\n");
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
int	exec_signal(int signal)
{
  if (signal == SIGBUS)
    {
      fprintf(stderr, "Bus error (bad memory access).\n");
      return (EXIT_FAILURE);
    }
  else if (signal == SIGFPE)
    {
      fprintf(stderr, "Floating point exception.\n");
      return (EXIT_FAILURE);
    }
  else if (signal == SIGSEGV)
    {
      fprintf(stderr, "Segmentation fault.\n");
      return (EXIT_FAILURE);
    }
  else if (signal == SIGILL)
    {
      fprintf(stderr, "Illegal Instruction.\n");
      return (EXIT_FAILURE);
    }
  else
    if ((exec_signal_other(signal)) == EXIT_FAILURE)
      return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}
