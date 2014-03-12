/*
** minishell.h for minishell in /home/platel_k/projet/minishell1/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 12 19:41:06 2011 kevin platel
** Last update Thu Dec 15 10:26:08 2011 kevin platel
*/

#ifndef __MINISHELL_H_
#define __MINISHELL_H_

#include "env.h"
#include "pwd.h"

void	exec(t_env *envp, char *buffer);
void	freewordtab(char **tab);
t_env	*add_new(char *field, t_env *begin);
t_env	*get_env(void);
char	*get_next_line(const int fd);
int	is_builtin(char *buffer, t_env **envp, t_pwd **my_pwd);
void	main_loop(t_env *env, t_pwd *my_pwd);
int     is_alnume(char c);
int	word_cnt(char *str);
char	**my_wordtab(char *str);
t_pwd	*change_dir(char *link, t_env *envp, t_pwd *my_pwd);
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

#endif
