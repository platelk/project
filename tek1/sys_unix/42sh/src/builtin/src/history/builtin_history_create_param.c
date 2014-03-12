/*
** builtin_history_create_param.c for 42sh in /home/phalip_z//exos/projets/42sh/42sh_builtin_history
** 
** Made by zoe phalippou
** Login   <phalip_z@epitech.net>
** 
** Started on  Tue May  1 11:28:51 2012 zoe phalippou
** Last update Sat May 12 19:10:11 2012 zoe phalippou
*/

#include	<stdlib.h>

#include	"my.h"
#include	"builtin_history_create_param.h"
#include	"builtin_history_param_firstpart.h"
#include	"xsys.h"
#include	"builtin_history_param_secondpart.h"

char	**create_args_history(void)
{
  char	**args;

  if ((args = xmalloc(sizeof(*args) * 6)) == NULL)
    return (NULL);
  args[0] = "-c";
  args[1] = "-r";
  args[2] = "-h";
  args[3] = "-S";
  args[4] = "-T";
  args[5] = NULL;
  return (args);
}

ptr_f_built_history *create_ptr_built_history(ptr_f_built_history *func)
{
  func[0] = &args_c;
  func[1] = &args_r;
  func[2] = &args_h;
  func[3] = &args_s;
  func[4] = &args_t;
  func[5] = NULL;
  return (func);
}
