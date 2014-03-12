/*
** minishell.h for minishell in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 12 19:41:06 2011 kevin platel
** Last update Sat Dec 31 01:28:06 2011 kevin platel
*/

#ifndef __MINISHELL_H_
#define __MINISHELL_H_

#include "env.h"
#include "pwd.h"
extern char **environ;

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
void	make_free(char ***tab, char ***path);
void	main_loop(t_env *env, t_pwd *my_pwd);
void	stop_signal(void);
void	error_sig(pid_t sig);
char	*link_cat(char *cmd, char *path);
t_pwd	*gest_cd(char *link, t_env *envp, t_pwd *my_pwd);
t_env	*add_new_with_two_arg(char *name, char *content, t_env *begin);
t_env	*un_set(char *buffer, t_env *envp);

#endif
