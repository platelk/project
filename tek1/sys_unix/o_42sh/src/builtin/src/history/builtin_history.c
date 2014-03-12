/*
** builtin_history.c for 42sh in /home/phalip_z//exos/projets/42sh/42sh_builtin_history
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue Apr 24 10:29:26 2012 zoe phalippou
** Last update Wed May  2 09:39:04 2012 zoe phalippou
*/

#include	<string.h>
#include	<stdio.h>
#include	<stdlib.h>

#include	"history_showlist.h"
#include	"builtin_history_create_param.h"
#include	"global.h"

static int	param_history(t_history **history, char **cmd)
{
  ptr_f_built_history func[8];
  char	**args;
  int	i;

  create_ptr_built_history(func);
  args = create_args_history();
  i = 0;
  if (cmd[1])
    while (func[i] && strncmp(args[i], cmd[1], strlen(args[i])))
      i++;
  if (func[i] == NULL)
    {
      if (cmd[1] && cmd[1][0] == '-')
	fprintf(stderr, "history: Badly formed number.\n");
      else
	fprintf(stderr, "Usage: history [-chrSLMT] [#number of events].\n");
      return (EXIT_FAILURE);
    }
  else
    if (!func[i](&cmd[1], history))
      return (EXIT_SUCCESS);
    else
      return (EXIT_FAILURE);
  return (EXIT_FAILURE);
}

int	check_history(t_global *global, char **cmd)
{
  if (!cmd[1])
    show_history(global->hist, -1);
  else if (cmd[1] && !put_error(cmd[1]) && !cmd[2])
    show_history(global->hist, atoi(cmd[1]));
  else if (cmd[1] || (cmd[1] && cmd[2]))
    {
      if (param_history(&global->hist, cmd))
	return (EXIT_FAILURE);
    }
  else
    {
      fprintf(stderr, "%s: Too many argument.\n", cmd[0]);
      return (EXIT_FAILURE);
    }
  return (EXIT_SUCCESS);
}
