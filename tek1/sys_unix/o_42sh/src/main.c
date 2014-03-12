/*
** main.c for 42sh in /home/vink/projet/sys_unix/42sh/src
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Apr 10 15:35:09 2012 kevin platel
*/

#include	<stdio.h>
#include	<stdlib.h>

#include	"sig.h"
#include	"sh.h"
#include	"t_history.h"
#include	"history_create_ptr_func.h"
#include	"history_putlist.h"
#include	"execute.h"
#include	"alias.h"
#include	"tree.h"
#include	"global.h"
#include	"my.h"
#include	"edit.h"
#include	"get_next_line.h"

t_global	global;

int	main(void)
{
  char		*cmd;
  t_node	*tree;
  int	exit;

  global.status = 0;
  global.env = creat_env();
  global.config = config_parser(".42shrc");
  global.hist = NULL;
  global.data = NULL;
  termcap_init(global.env);
  stop_signal();
  while (!global.status)
    {
      tree = NULL;
      global.prompt = edit_prompt(global.config, global.env);
      if ((cmd = edit_cmd(&global, global.prompt)) == NULL && !global.status)
	global.status = !global.status;
      if (!global.status)
	if (is_singlestr(' ', cmd) && (tree = parsing_func(cmd, &global)))
	  if ((exit = exec_course_tree(tree, global.env, &global)) == EXIT_CHILD)
	    return (exit);
      (cmd) ? free(cmd) : (cmd = NULL);
      (global.prompt) ? free(global.prompt) : (global.prompt = NULL);
    }
  return (exit);
}
