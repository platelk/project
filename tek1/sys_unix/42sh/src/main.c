/*
** main.c for 42sh in /home/vink/projet/sys_unix/42sh/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Thu May 17 17:30:17 2012 kevin platel
** Last update Tue Dec 18 16:01:26 2012 kevin platel
*/

#include	<stdio.h>
#include	<stdlib.h>
#include	<sys/stat.h>

#include	"../include/sig.h"
#include	"../include/sh.h"
#include	"../include/t_history.h"
#include	"../include/history_showlist.h"
#include	"../include/history_create_ptr_func.h"
#include	"../include/history_create_list.h"
#include	"../include/history_putlist.h"
#include	"../include/execute.h"
#include	"../include/alias.h"
#include	"../include/tree.h"
#include	"../include/global.h"
#include	"../include/my.h"
#include	"../include/edit.h"
#include	"../include/free_child.h"
#include	"../include/get_next_line.h"

t_global	global;

static void	init_global(void)
{
  global.echo = 0;
  global.status = 0;
  global.env = creat_env();
  global.config = config_parser(".mshrc");
  global.hist = NULL;
  global.hist = history_create_list(global.config, &global.hist);
  global.data = NULL;
  global.ctrlc = 0;
  termcap_init(global.env);
  global.exit = 0;
  stop_signal();
}

int	main(void)
{
  char		*cmd;
  t_node	*tree;

  init_global();
  while (!global.status)
    {
      tree = NULL;
      global.prompt = edit_prompt(global.config, global.env);
      if ((cmd = edit_cmd(&global, global.prompt)) == NULL && !global.status)
	global.status = !global.status;
      if (my_strlen(cmd) >= MAX_LINE_NUMBER)
	fprintf(stderr, "%s: File name too long\n", cmd);
      else if (!global.status)
	if (is_singlestr(' ', cmd) && (tree = parsing_func(cmd, &global, 0)))
	  if ((exec_course_tree(tree, global.env, &global)) == EXIT_CHILD)
	    {
	      sh_free(&global, tree, cmd);
	      (global.prompt) ? free(global.prompt) : (global.prompt = NULL);
	      return (global.exit);
	    }
      sh_free(NULL, tree, cmd);
      (global.prompt) ? free(global.prompt) : (global.prompt = NULL);
    }
  sh_free(&global, NULL, NULL);
  return (global.exit);
}
