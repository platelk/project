/*
** edit_cmd.c for 42sh in /home/vink/projet/sys_unix/42sh/src/edit/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 18 22:21:34 2012 kevin platel
** Last update Wed May  2 09:41:59 2012 kevin platel
*/

#include        <stdio.h>
#include        <stdlib.h>
#include	<unistd.h>
#include	<termios.h>

#include        "global.h"
#include        "my.h"
#include        "edit.h"
#include        "get_next_line.h"
#include	"xsys.h"
#include	"builtin.h"

static void	edit_exit(t_global *global)
{
  char	*tab[3];

  tab[0] = "exit";
  tab[1] = "0";
  tab[2] = NULL;
  builtin_exit(global, tab);
}

t_line   *edit_management(t_global *global, char *prompt)
{
  t_line	*line;
  t_efunc	*func;
  char	**keyword;
  char	*buff;

  if ((keyword = edit_keyword()) == NULL ||
      (func = edit_func()) == NULL ||
      (buff = xmalloc(sizeof(*buff) * (MAX_BUFFER_LENGTH + 1))) == NULL)
    return (NULL);
  line = NULL;
  global->curser = 0;
  while (read(0, buff, MAX_BUFFER_LENGTH) > 0 &&
	 my_strcmp(buff, ENTER_EDIT_STRING) &&
	 my_strcmp(buff, CTRLD_EDIT_STRING))
    {
      func[edit_iskeyword(buff, keyword)](global, &line, prompt, buff);
      my_clstr(buff, MAX_BUFFER_LENGTH);
      termcap_display(line, global->curser);
    }
  if (!my_strcmp(buff, CTRLD_EDIT_STRING))
    edit_exit(global);
  else
      my_putchar('\n');
  (buff) ? free(buff) : (buff = NULL);
  return (line);
}

char	*edit_cmd(t_global *global, char *prompt)
{
  t_line	*line;
  char	*cmd;
  struct termios t;

  if ((tcgetattr(0, &t) == -1 ||
			      termcap_raw(&t, 0) || termcap_echo(&t, 0)))
    return (get_next_line(0));
  my_putstr(prompt);
  line = edit_management(global, prompt);
  cmd = edit_convertlist(line);
  while (global->hist && global->hist->next)
    global->hist = global->hist->next;
  if (line)
    edit_freelist(line);
  if (termcap_raw(&t, 1) || termcap_echo(&t, 1))
    return (NULL);
  return (cmd);
}
