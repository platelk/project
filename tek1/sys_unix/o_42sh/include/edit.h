/*
** edit.h for 42sh in /home/leprov_a//depot/42sh/src/edit/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 17:43:07 2012 alexis leprovost
** Last update Sun Apr 29 13:29:04 2012 alexis leprovost
*/

#ifndef __EDIT_H__
#define __EDIT_H__

#include	<termios.h>

#include	"env.h"
#include	"get_next_line.h"
#include	"global.h"

#define	DEFAULT_PROMPT_STRING	"> "
#define	DEFAULT_TERM_STRING	"xterm"

#define HOSTNAME_STRING	"HOSTNAME"
#define USERNAME_STRING	"USERNAME"
#define PWD_STRING	"PWD"
#define TERM_STRING	"TERM"

#define	ESCAPE_EDIT_STRING	"\033"
#define ENTER_EDIT_STRING	"\n"
#define UP_EDIT_STRING	"\033[A"
#define DOWN_EDIT_STRING	"\033[B"
#define RIGHT_EDIT_STRING	"\033[C"
#define LEFT_EDIT_STRING	"\033[D"
#define	CLEAR_EDIT_STRING	"\f"
#define	DELETE_EDIT_STRING	"\177"
#define SUPPR_EDIT_STRING	"\033\133\063\176"
#define	START_EDIT_STRING	"\1"
#define	END_EDIT_STRING	"\5"
#define	CTRLF_EDIT_STRING	"\006"
#define CTRLB_EDIT_STRING	"\002"
#define	CTRLH_EDIT_STRING	"\010"
#define CTRLP_EDIT_STRING	"\020"
#define CTRLY_EDIT_STRING	"\031"
#define	CTRLU_EDIT_STRING	"\025"
#define CTRLT_EDIT_STRING	"\024"
#define	CTRLK_EDIT_STRING	"\013"
#define CTRLW_EDIT_STRING	"\027"
#define CTRLD_EDIT_STRING	"\004"
#define	CTRLX_EDIT_STRING	"\030"
#define CTRLFG_EDIT_STRING	"\033\133\061\073\065\104"
#define CTRLFD_EDIT_STRING	"\033\133\061\073\065\103"
#define	TAB_EDIT_STRING	"\t"

#define	CUSTOM_CHAR	'%'

#define MAX_PROMPT_LENGTH	1024
#define	MAX_BUFFER_LENGTH       20
#define	MAX_EDIT_KEYWORD_NUMBER	23

#define CONTROL_STRING	"ce"
#define	BACKWARD_STRING	"dc"
#define RIGHT_MOVE_STRING	"nd"
#define LEFT_MOVE_STRING	"le"
#define	CLEAR_MOVE_STRING	"cl"

typedef enum e_edit
{
  DELETE,
  RIGHT,
  LEFT,
  UP,
  DOWN
} t_edit;

typedef	int	(*t_efunc)(t_global *, t_line **, char *, char *);

void	edit_freelist(t_line *line);
void	edit_afflist(t_line *line);
char	*edit_prompt(t_config *config, t_env *env);
char	*edit_cmd(t_global *glob, char *prompt);
char	*edit_convertlist(t_line *line);
int	edit_listlen(t_line *line);
int	edit_putlist(t_line **begin, char letter);
t_line	*edit_concatlist(t_line *p1, t_line *p2, int n);
t_line	*edit_convertstr(char *str);
t_line	*edit_management(t_global *global, char *prompt);
char	**edit_keyword(void);
int	edit_iskeyword(char *str, char **keyword);
t_efunc	*edit_func(void);

int	edit_suppr(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_delete(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_default(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_move(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_leftmove(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_rightmove(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_uphistory(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_downhistory(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_clear(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_swap(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_allstore(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_rightstore(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_leftstore(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_paste(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_control(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_switchmove(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_goto_nextspace(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_goto_prevspace(t_global *global, t_line **line, char *prompt, char *buff);
int	edit_globing(t_global *global, t_line **line, char *prompt, char *buff);

int	termcap_init(t_env *env);
int	termcap_raw(struct termios *t, int flag);
int	termcap_echo(struct termios *t, int flag);
int	termcap_delete(int size, char *flag);
int	termcap_action(int size, char *flag);
int	termcap_put(int cap);
int	termcap_display(t_line *line, int cm);

char	*tgoto(const char *cap, int col, int row);
char	*tgetstr(char *id, char **area);
int	tputs(const char *str, int afffcnt, int (*putc)(int));

#endif
