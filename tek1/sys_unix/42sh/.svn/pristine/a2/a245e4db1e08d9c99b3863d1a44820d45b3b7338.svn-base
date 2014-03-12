/*
** glob_hist.c for glob_hist in /home/vink/projet/sys_unix/42sh/src
**
** Made by kevin platel
** Login   <vink@epitech.net>
**
** Started on  Tue May  8 22:57:46 2012 kevin platel
** Last update Sat May 19 14:22:21 2012 kevin platel
*/

#include	<stdlib.h>
#include	<stdio.h>

#include	"my.h"
#include	"sh.h"
#include	"globing.h"
#include	"token.h"
#include	"global.h"
#include	"history_putlist.h"
#include	"history_substitution.h"

void	glob_print_hist(int i, t_token *new, void **ret, t_global *glob)
{
  char	*tmp;

  if (i == 0 || *ret != NULL)
    history_putlist(get_cmd_in_list(new), &(glob->hist), glob->config);
  if (i != 0 && new)
    {
      tmp = get_cmd_in_list(new);
      if (tmp)
	{
	  printf("%s\n", tmp);
	  free(tmp);
	}
    }
}

t_token	*glob_hist(t_token *new, t_global *glob, void **ret)
{
  t_token	*tmp;
  int		i;

  tmp = new;
  i = 0;
  while (*ret && tmp)
    {
      if ((int) tmp->spec == HISTORY && ++i)
	{
	  tmp = sep_in_dif_tok(tmp,
			       my_strdup(*ret =
					 history_substitution(tmp->content,
							      glob->hist,
							      put_str_subs())),
			       VARIABLES);
	  if ((*ret) == NULL)
	    (tmp->content = my_strdup("\0"));
	  tmp = glob_gest_tok_list(tmp, glob, 1, NULL);
	  new = analyse_cmd(get_cmd_in_list(new));
	}
      tmp = tmp->next;
    }
  glob_print_hist(i, new, ret, glob);
  return (new);
}
