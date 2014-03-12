/*
** edit_globing.c for 42sh in /home/leprov_a//depot/42sh/src/edit/src
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sat Apr 28 18:20:41 2012 alexis leprovost
** Last update Mon Apr 30 19:28:32 2012 alexis leprovost
*/

#include	<stdlib.h>
#include	<unistd.h>

#include	"global.h"
#include	"edit.h"
#include	"xsys.h"
#include	"t_history.h"
#include	"get_next_line.h"
#include	"globing.h"
#include	"my.h"

static char	*edit_replacelist(t_line *line)
{
  char	*str;
  int	len;
  int	i;

  i = -1;
  len = 0;
  while (line && !line->status)
    line = line->next;
  if (line == NULL)
    return (my_strdup("*"));
  while (line && line->prev && line->letter != ' ')
    {
      ++len;
      line = line->prev;
    }
  if ((str = xmalloc(sizeof(*str) * (len + 3))) == NULL)
    return (NULL);
  while (line && !line->status)
    {
      str[++i] = line->letter;
      line = line->next;
    }
  if (line->next == NULL)
    str[++i] = line->letter;
  str[++i] = '*';
  str[++i] = '\0';
  return (str);
}

static t_line	*edit_cmpstr(char **tab)
{
  if (my_tablen(tab) == 1)
    return (edit_convertstr(tab[0]));
  tab = tab;
  return (NULL);
}

static int	edit_showglob(t_line *line, char **tab, char *prompt, int curser)
{
  char	*str;
  int	i;

  i = -1;
  my_putchar('\n');
  while (tab && tab[++i])
    printf("%s\n", tab[i]);
  my_putstr(prompt);
  str = edit_convertlist(line);
  my_putstr(str);
  if (termcap_action(edit_listlen(line) - curser, LEFT_MOVE_STRING))
    return (EXIT_FAILURE);
  return (EXIT_SUCCESS);
}

int
edit_globing(t_global *global, t_line **line, char *prompt, char *buff)
{
  t_line	*tmp;
  char	**tab;
  char	*s1;
  char	*s2;

  if (global->config == NULL || !global->config->option[COMPLETE])
    return (EXIT_FAILURE);
  s1 = edit_replacelist(*line);
  s2 = globing(s1, global, 0);
  (s1) ? (free(s1)) : (s1 = NULL);
  tab = my_strtok(s2, " ", TOK_DELIM);
  (s2) ? (free(s2)) : (s2 = NULL);
  tmp = edit_cmpstr(tab);
  *line = edit_concatlist(*line, tmp, global->curser);
  global->curser += edit_listlen(tmp);
  if (my_tablen(tab) > 1)
    edit_showglob(*line, tab, prompt, global->curser);
  edit_freelist(tmp);
  buff = buff;
  return (EXIT_SUCCESS);
}
