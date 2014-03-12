/*
** main.c for 42sh in /home/leprov_a//depot/42sh/src/edit
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 23 11:15:33 2012 alexis leprovost
** Last update Sat Apr 28 17:58:52 2012 alexis leprovost
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<termios.h>

#include	"t_history.h"
#include	"history_putlist.h"
#include	"edit.h"
#include	"config.h"
#include	"env.h"

int	main(void)
{
  t_global	global;
  char	*prompt;
  char	*cmd;
  struct termios t;

  if (tcgetattr(0, &t) == -1)
    {
      printf("Tcgetattr FAIL.\n");
      return (EXIT_FAILURE);
    }
  global.hist = NULL;
  global.data = NULL;
  global.config = config_parser(".test");
  printf("KEVIN EST\n");
  global.env = creat_env();
  printf("NOOB\n");
  history_putlist("LOl", &global.hist);
  history_putlist("TEST", &global.hist);
  history_putlist("KEVIN", &global.hist);
  history_putlist("NOOB", &global.hist);
  history_putlist("TROOLOLOl", &global.hist);
  if (global.config)
    {
      if ((prompt = edit_prompt(global.config, global.env)))
	printf("PROMPT OK - %s\n", prompt);
      else
	printf("PROMPT FAIL\n");
      if (!termcap_init(global.env))
	printf("TERMCAP INIT OK\n");
      else
	printf("TERMCAP INIT FAIL\n");
      while ((cmd = edit_cmd(&global, prompt)) != NULL)
	printf("%s\n", cmd);
    }
  return (EXIT_SUCCESS);
}
