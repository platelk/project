/*
** my.h for 42sh in /home/leprov_a//depot/42sh/src/config/lib
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Mon Apr 16 01:00:35 2012 alexis leprovost
** Last update Sun Jun  3 19:38:01 2012 harold ozouf
*/

#ifndef __MY_H__
#define __MY_H__

#include	<stdarg.h>
#include	<stdlib.h>

#define	NUMBER_STRING	"+-0123456789"
#define	ALPHA_STRING	"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define	DELIM_NUMBER	",."

char    find_intab(char);
int     my_printf(const char *, ...);
int     opt_d(va_list *, const char *);
int     opt_s(va_list *, const char *);
int     opt_c(va_list *, const char *);
int     opt_x(va_list *, const char *);
int     opt_X(va_list *, const char *);
int     opt_o(va_list *, const char *);
int     opt_u(va_list *, const char *);
int     opt_b(va_list *, const char *);
int     opt_S(va_list *, const char *);
int     opt_mod(va_list *, const char *);
int     opt_p(va_list *, const char *);
int     opt_less(const char *, int);
int     opt_pres(const char *, int);
int     my_putnbr_base(int, char *);
void	*init_tab_func(void);
int     my_putnbrul_base(unsigned long int, char *);
int     error(const char *);
int     put_oct(char);
int	opt(const char *, int *, int *, va_list *);
int	isnum(char);
int	is_alpha(char);
int	is_number(char *);
double	my_sqrt(double);
void	my_free_tab(char **);
void	my_putchar(char);
void	my_putnbr(int);
int	my_putstr(char *);
int	my_strlen(char *);
int	my_tablen(char **);
int	my_strcmp(char *, char *);
int	my_strncmp(char *, char *, int);
int	check_base(char, char *);
int	my_getnbr(char *);
int	my_getnbr_base(char *, char *);
int	is_a_number(char *);
int	is_a_singlestr(char, char *);
int	my_clstr(char *, int);
int	my_puterror(char *);
int	my_power_rec(int, int);
int	my_strstr(char *, char *);
double	my_getdouble(char *);
char	*my_strdup(char *);
char	*my_strndup(char *, int);
char	*my_strconcat(char *, char *);
char	*my_strcat(char *, char *);
char	*my_strmcat(char *, char *);
char	*my_strcpy(char *, char *);
char	*epur_str(char *);
void	*xmalloc(size_t);
int	my_putdouble(double);
#endif
