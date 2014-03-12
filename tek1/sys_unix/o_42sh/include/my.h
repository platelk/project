/*
** my.h for 42sh in /home/leprov_a//depot/42sh/src/config/lib
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 01:00:35 2012 alexis leprovost
** Last update Sun Apr 29 13:11:16 2012 kevin platel
*/

#ifndef __MY_H__
#define __MY_H__

#define	NUMBER_STRING	"+-0123456789"
#define	ALPHA_STRING	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"

#include "my_strtok.h"

void	my_free_tab(char **tab);
void	my_putchar(char c);
int	my_putstr(char *str);
int	my_strlen(char *str);
int	my_tablen(char **tab);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
int	check_base(char c, char *base);
int	my_getnbr(char *str);
int	isanumber(char *str);
int	is_singlestr(char c, char *str);
int	my_clstr(char *str, int size);
char	*my_strdup(char *str);
char	*my_strconcat(char *s1, char *s2);
char	*my_strcat(char *s1, char *s2);
char	*my_strcpy(char *s1, char *s2);
int	**malloc_int_tab(int nb_col, int nb_ligne);
char	*my_strmcat(char *dest, char *src);

#endif
