/*
** my_ls.h for my_ls in /home/platel_k/projet/my_ls/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Nov 21 20:12:51 2011 kevin platel
** Last update Sun Dec  4 14:01:40 2011 kevin platel
*/

#ifndef __MY_LS__
#define __MY_LS__

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#include "my.h"
#include "data.h"

#define NAME_DIR	(direc->name)
#define IS_POINT	(my_strcmp(direc->name, "..") != 0 &&my_strcmp(direc->name, "."))

void	rev(t_data **begin);
void	rev_list(t_data **directory);
void	my_put_right(struct stat *info);
int     get_opt(int ac, char **av);
void    find_in_opt(char c, int *opt);
void    find_in_list_str(char *str, int *opt);
char	**get_link(int ac, char **av);
int	my_sort_list(t_data **begin, int (*cmp)());
t_data	*my_list_swap(t_data *begin);
t_data	*add_new(t_data **list, char *name);
int	my_sort_by_alpha(char *str1, char *str2);
char	*str_upper(char	*str);
int	show_dir(char *link, int opt);
t_data		*get_data(char *link, int opt, DIR **dir);
t_data		*del_in_list(t_data *begin);
void	listing(t_data *directory, char *link, int opt);
void	put_id(uid_t pwuid);
void	put_gid(gid_t gruid);
int		my_sort_list_time(t_data **begin, char *link);
int	time_file(t_data *directory, char *link);
int	is_dir(t_data *directory, char *link);
char	*link_of_file(char *link, t_data *directory);
void	aff_ls(t_data *directory, int opt, char *link, t_data **dir);
void	size_tot(t_data *directory, char *link);

#endif
