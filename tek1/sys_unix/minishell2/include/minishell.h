/*
** minishell.h for minishell in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 12 19:41:06 2011 kevin platel
** Last update Tue Feb 28 18:26:26 2012 kevin platel
*/

#ifndef __MINISHELL_H_
#define __MINISHELL_H_

#include "env.h"
#include "pwd.h"
#include "cmd.h"

extern char **environ;

#define	ERROR	(-1)
#define TABULATION	(4)
#define SET	(1)
#define UNSET	(0)
#define UP	(65)
#define DOWN	(66)
#define LEFT	(68)
#define RIGHT	(67)
#define QUIT	('\n')
#define SELECT  (' ')
#define DELETE  (127)
#define ECHAP	(27)

#define	PIPE		(1)
#define	RED_RIGHT	(2)
#define RED2_RIGHT	(4)
#define	RED_LEFT	(8)
#define RED2_LEFT	(16)

#define STR_PIPE       "|"
#define STR_RED_RIGHT  ">"
#define STR_RED2_RIGHT ">>"
#define STR_RED_LEFT   "<"
#define STR_RED2_LEFT  "<<"

int tgetent(char *bp, const char *name);
char *tgetstr(char *id, char **area);
int tputs(const char *str, int affcnt, int (*putc)(int));

void	free_env(t_env *env);
void	exec(t_env *envp, char *buffer);
char	**freewordtab(char **tab);
t_env	*add_new(char *field, t_env *begin);
t_env	*get_env(char **envp);
char	*get_next_line(const int fd, t_env *env, t_pwd *my_pwd);
int	is_builtin(char *buffer, t_env **envp, t_pwd **my_pwd);
void	main_loop(t_env *env, t_pwd *my_pwd);
int     is_alnume(char c);
int	word_cnt(char *str);
char	**my_wordtab(char *str);
t_pwd	*change_dir(char *link, t_env **envp, t_pwd *my_pwd);
void	show_dir(t_pwd *my_pwd);
t_env	*environ_set(char *buffer, t_env *envp);
char	**my_link_wordtab(char *str);
int	word_counter(char *str);
int     is_aln(char c);
t_pwd	*new_pwd(char *element, t_pwd *my_pwd);
t_pwd	*del_one_pwd(t_pwd *pwd);
t_pwd	*creat_pwd(char *link);
t_pwd   *update_pwd(char *link, t_pwd *my_pwd);
char	*pwd_to_char(t_pwd *my_pwd);
void	free_pwd(t_pwd *my_pwd);
t_pwd	*add_pwd(char *element, t_pwd *my_pwd);
int     is_egal(char c);
int	word(char *str);
t_pwd	*go_to_home(t_env *envp, t_pwd *my_pwd);
char	**my_env_wordtab(char *str);
int	word(char *str);
void	quit(t_env *envp, t_pwd *my_pwd);
void	make_free(char **tab, char **path);
void	main_loop(t_env *env, t_pwd *my_pwd);
void	stop_signal(void);
void	error_sig(pid_t sig);
char	*link_cat(char *cmd, char *path);
t_pwd	*gest_cd(char *link, t_env *envp, t_pwd *my_pwd);
t_env	*add_new_with_two_arg(char *name, char *content, t_env *begin);
t_env	*un_set(char *buffer, t_env *envp);

int	init(char **envp);
int	screen_clean(void);
int	mouv_curs(int x, int y);
int	visible_cursor(int mode);
int	echo_mode(int mode);
int	raw_mode(int mode);
int	use_termcap(char *cap);
t_cmd	*gest_red_right(t_cmd *cmd);
int	exec_cmd(char *cmd, t_env **envp);
int	my_is_operand(char *str);
t_cmd	*aply_operand(char *cmd, int operand, t_cmd *command);
int	builtin(char *buffer);
char    treatment_of_data(void);
int	exec_cmd(char *cmd, t_env **envp);
int   mov_curs(int c, int i, int *j);
int	gest_cmd(t_env *envp, t_pwd *my_pwd);
t_cmd	*analyse_cmd(char *cmd);
int	exec_comd(t_cmd *cmd, t_env **envp, t_pwd **my_pwd);
char	*show_prompt(t_env *env, t_pwd *my_pwd);
char	*get_cmd(void);

#endif
