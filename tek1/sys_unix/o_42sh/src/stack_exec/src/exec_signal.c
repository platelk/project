/*
** exec_signal.c for exec_stack in /home/guiho_r/tek1/42sh/src/stack_exec/src
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Apr 19 11:31:03 2012 ronan guiho
** Last update Sat Apr 28 15:01:12 2012 ronan guiho
*/

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

int	exec_signal(int signal)
{
  if (signal == SIGBUS)
    fprintf(stderr, "Bus error (bad memory access).\n");
  else if (signal == SIGFPE)
    fprintf(stderr, "Floating point exception.\n");
  else if (signal == SIGSEGV)
    fprintf(stderr, "Segmentation fault.\n");
  else if (signal == SIGILL)
    fprintf(stderr, "Illegal Instruction.\n");
  else if (signal == SIGSYS)
    fprintf(stderr, "Bad argument to routine.\n");
  else if (signal == SIGTRAP)
    fprintf(stderr, "Trace/breakpoint trap.\n");
  else if (signal == SIGIOT)
    fprintf(stderr, "IOT trap.\n");
  else if (signal == SIGQUIT)
    fprintf(stderr, "Quit from keyboard.\n");
  return (EXIT_SUCCESS);
}
