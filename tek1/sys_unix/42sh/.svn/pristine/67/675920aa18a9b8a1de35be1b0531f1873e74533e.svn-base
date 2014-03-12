/*
** sh_free.c for free in /home/vink/projet/sys_unix/42sh/src/env/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Wed May 16 17:35:26 2012 kevin platel
** Last update Sat May 19 14:36:50 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"sh.h"
#include	"config.h"
#include	"tree.h"
#include	"env.h"
#include	"free_child.h"
#include	"history_putlist.h"
#include	"history_create_list.h"

void	sh_free(t_global *global, t_node *tree, char *cmd)
{
  if (cmd)
    free(cmd);
  if (tree)
    free_node(tree);
  if (global)
    {
      if (global->env)
	env_free(global->env);
      history_file_config(global->config, global->hist);
      if (global->hist)
	{
	  while (global->hist && global->hist->next)
	    global->hist = global->hist->next;
	  free_history(global->hist);
	}
      if (global->config)
	config_free(global->config);
    }
}
