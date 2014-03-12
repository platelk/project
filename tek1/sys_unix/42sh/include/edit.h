/*
** edit.h for 42sh in /home/leprov_a//depot/42sh/src/edit/inc
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 17:43:07 2012 alexis leprovost
** Last update Sat May 19 10:49:01 2012 alexis leprovost
*/

#ifndef __EDIT_H__
#define __EDIT_H__

#include	<termios.h>
#include	<sys/ioctl.h>

#include	"env.h"
#include	"get_next_line.h"
#include	"global.h"

#define NUMBER(value)	((value) >= '0' && (value) <= '9' ? 1 : 0)

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
#define CTRLR_EDIT_STRING	"\022"
#define CTRLFG_EDIT_STRING	"\033\133\061\073\065\104"
#define CTRLFD_EDIT_STRING	"\033\133\061\073\065\103"
#define	TAB_EDIT_STRING	"\t"

#define	CUSTOM_CHAR	'%'

#define MAX_PROMPT_LENGTH	1024
#define	MAX_BUFFER_LENGTH       20
#define	MAX_EDIT_KEYWORD_NUMBER	24
#define	MAX_LINE_NUMBER		4092

#define	INSERT_ON	"im"
#define INSERT_OFF	"ei"

#define	CURSER_ON	"ve"
#define CURSER_OFF	"vi"

#define VM_ON		"mr"
#define VM_OFF		"me"

#define UNDERLINE_ON	"us"
#define UNDERLINE_OFF	"ue"

#define CONTROL_STRING	"ce"
#define	BACKWARD_STRING	"dc"
#define RIGHT_MOVE_STRING	"nd"
#define LEFT_MOVE_STRING	"le"
#define	CLEAR_MOVE_STRING	"cl"
#define CD_MOVE_STRING		"cd"
#define UP_MOVE_STRING		"up"
#define DOWN_MOVE_STRING	"do"

typedef enum e_edit
{
  DELETE,
  RIGHT,
  LEFT,
  UP,
  DOWN
} t_edit;

typedef	int	(*t_efunc)(t_global *, t_line **, char *, char *);

void	edit_freelist(t_line *);
void	edit_afflist(t_line *);
char	*edit_prompt(t_config *, t_env *);
char	*edit_cmd(t_global *, char *);
char	*edit_convertlist(t_line *);
int	edit_listlen(t_line *);
int	edit_putlist(t_line **, char);
t_line	*edit_concatlist(t_line *, t_line *, int);
t_line	*edit_convertstr(char *);
t_line	*edit_management(t_global *, char *);
void	edit_keyword(char **);
int	edit_iskeyword(char *, char **);
t_efunc	*edit_func(void);
int	edit_cp(t_line *);

int	edit_suppr(t_global *, t_line **, char *, char *);
int	edit_delete(t_global *, t_line **, char *, char *);
int	edit_default(t_global *, t_line **, char *, char *);
int	edit_move(t_global *, t_line **, char *, char *);
int	edit_leftmove(t_global *, t_line **, char *, char *);
int	edit_rightmove(t_global *, t_line **, char *, char *);
int	edit_uphistory(t_global *, t_line **, char *, char *);
int	edit_downhistory(t_global *, t_line **, char *, char *);
int	edit_clear(t_global *, t_line **, char *, char *);
int	edit_swap(t_global *, t_line **, char *, char *);
int	edit_allstore(t_global *, t_line **, char *, char *);
int	edit_rightstore(t_global *, t_line **, char *, char *);
int	edit_leftstore(t_global *, t_line **, char *, char *);
int	edit_paste(t_global *, t_line **, char *, char *);
int	edit_control(t_global *, t_line **, char *, char *);
int	edit_switchmove(t_global *, t_line **, char *, char *);
int	edit_goto_nextspace(t_global *, t_line **, char *, char *);
int	edit_goto_prevspace(t_global *, t_line **, char *, char *);
int	edit_globing(t_global *, t_line **, char *, char *);
int	edit_strstr(t_global *, t_line **, char *, char *);
int     edit_global(t_global *, int);
int     edit_env(t_config *, t_env **);

int	termcap_init(t_env *);
int	termcap_raw(struct termios *, int);
int	termcap_echo(struct termios *, int);
int	termcap_delete(int , char *, t_global *, int);
int	termcap_action(int , char *, t_global *, int);
int	termcap_put(int);
int	termcap_display(t_line *, t_global *);
int     termcap_ioctl(struct winsize *);
int	termcap_move(t_global *, int, int *);
int	termcap_prompt(char *, int);

void	ultim_func(t_line *, t_global *);

char	*tgoto(const char *, int, int);
char	*tgetstr(char *, char **);
int	tputs(const char *, int, int (*)(int));

#endif
