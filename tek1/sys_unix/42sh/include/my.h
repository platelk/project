/*
** my.h for 42sh in /home/leprov_a//depot/42sh/src/config/lib
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 01:00:35 2012 alexis leprovost
** Last update Sat May 19 10:56:24 2012 alexis leprovost
*/

#ifndef __MY_H__
#define __MY_H__

#define	NUMBER_STRING	"+-0123456789"
#define	ALPHA_STRING	"abcdefghijklmnopqrstuvwxyz \
			ABCDEFGHIJKLMNOPQRSTUVWXYZ"

#include "my_strtok.h"

int	my_strsearch(char *, char);
void	my_free_tab(char **);
void	my_putchar(char);
int	my_putstr(char *);
int	my_strlen(char *);
int	my_tablen(char **);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
int	check_base(char, char *);
int	my_getnbr(char *);
int	isanumber(char *);
int	is_singlestr(char, char *);
int	my_clstr(char *, int);
char	*my_strdup(char *);
char	*my_strconcat(char *, char *);
char	*my_strcat(char *, char *);
char	*my_strcpy(char *, char *);
int	**malloc_int_tab(int, int);
char	*my_strmcat(char *, char *);
char	*my_revstr(char *);

#endif
