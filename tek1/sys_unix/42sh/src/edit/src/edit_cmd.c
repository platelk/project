/*
** edit_cmd.c for 42sh in /home/vink/projet/sys_unix/42sh/src/edit/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Apr 18 22:21:34 2012 kevin platel
** Last update Sat May 19 13:10:55 2012 alexis leprovost
*/

#include        <stdio.h>
#include        <stdlib.h>
#include	<unistd.h>
#include	<termios.h>
#include	<sys/ioctl.h>

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

int	edit_global(t_global *global, int flag)
{
  struct winsize argp;

  if (termcap_ioctl(&argp) || global == NULL)
    return (EXIT_FAILURE);
  global->dom[X] = argp.ws_col;
  global->dom[Y] = argp.ws_row;
  if (flag)
    {
      global->curser[X] = 0;
      global->curser[Y] = 0;
    }
  return (EXIT_SUCCESS);
}

static int	edit_strlen(char *str)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  while (str && str[i])
    {
      if (str[i] == '\033' && str[i + 1] == '[' && NUMBER(str[i + 2]) &&
	  str[i + 3] == ';' && NUMBER(str[i + 4]) && NUMBER(str[i + 5]) &&
	  str[i + 6] == 'm')
	i += 7;
      else if (str[i] == '\033' && str[i + 1] == '[' && str[i + 2] == '0' &&
	       str[i + 3] == 'm')
	i += 4;
      else
	{
	  ++i;
	  ++ret;
	}
    }
  return (ret);
}

t_line   *edit_management(t_global *global, char *prompt)
{
  t_line	*line;
  t_efunc	*func;
  char	*keyword[MAX_EDIT_KEYWORD_NUMBER];
  char	buff[MAX_BUFFER_LENGTH + 1];

  edit_keyword(keyword);
  if ((func = edit_func()) == NULL)
    return (NULL);
  line = NULL;
  my_clstr(buff, MAX_BUFFER_LENGTH);
  while (read(0, buff, MAX_BUFFER_LENGTH) > 0 &&
	 my_strcmp(buff, ENTER_EDIT_STRING) &&
	 my_strcmp(buff, CTRLD_EDIT_STRING) &&
	 global->ctrlc == 0)
    {
      edit_global(global, 0);
      func[edit_iskeyword(buff, keyword)](global, &line, prompt, buff);
      my_clstr(buff, MAX_BUFFER_LENGTH);
    }
  if (!my_strcmp(buff, CTRLD_EDIT_STRING) && edit_listlen(line) == 0)
    edit_exit(global);
  else if (global->ctrlc == 0)
    my_putchar('\n');
  (func) ? free(func) : (func = NULL);
  return (line);
}

char	*edit_cmd(t_global *global, char *prompt)
{
  t_line	*line;
  char	*cmd;
  struct termios t;

  edit_env(global->config, &global->env);
  if ((tcgetattr(0, &t) == -1 || global == NULL ||
       termcap_raw(&t, 0) || termcap_echo(&t, 0)))
    {
      (global) ? (global->echo = 1) : (EXIT_FAILURE);
      return (get_next_line(0));
    }
  edit_global(global, 1);
  global->ctrlc == 0 ? termcap_prompt(prompt, (global->dom[X] - 1)) :
    (global->ctrlc = 0);
  global->len = edit_strlen(prompt);
  (global->len > (global->dom[X] - 1)) ? (global->len = (global->dom[X] - 1)) :
    (global->len = global->len);
  line = edit_management(global, prompt);
  global->ctrlc ? (cmd = my_strdup("\0")) : (cmd = edit_convertlist(line));
  while (global->hist && global->hist->next)
    global->hist = global->hist->next;
  (line) ? edit_freelist(line) : (line = NULL);
  if (termcap_raw(&t, 1) || termcap_echo(&t, 1))
    return (NULL);
  return (cmd);
}
