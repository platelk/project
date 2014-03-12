/*
** my.h for my.h in /home/platel_k//projet/piscine/Jour_09
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Oct 13 10:50:00 2011 kevin platel
** Last update Sun Mar 18 13:30:53 2012 alexis leprovost
*/

#ifndef __MY_H__
#define __MY_H__

#include <stdarg.h>

#include "get_next_line.h"

#define	IS_IN_STR	0
#define	IS_NOT_STR	-1

int     my_nbr_malloc(int nbr, char *base, int c);
char    *my_nbr_base(int nbr, char *base, char *new, int c);
char	*convert_base(char *nbr, char *base_from, char *base_to);
int	my_factorielle_rec(int nb);
int	my_find_prime_sup(int nbr);
int	my_nbr(char *str, int c);
int	my_getnbr(char *str);
int	my_is_prime(int nbr);
int	my_power_rec(int nb, int power);
void	my_putchar(char c);
int	my_putnbr_base(int nbr, char *base);
int	my_putnbr(int nbr);
int	my_putstr(char *str);
int	my_strleng(char *str);
char	*my_revstr(char *str);
int	my_show_wordtab(char **wordtab);
int     my_swap(int *a, int *b);
void	my_sort_int_tab(int *tab, int size);
int	my_square_root(int nbr);
char	*my_strcapitalize(char *str);
char	*my_strcat(char *dest, char *src);
int	my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *src);
int	my_str_isalpha(char *str);
int     my_str_islower(char *str);
int     my_str_isnum(char *str);
int     my_str_isprintable(char *str);
int     my_str_isupper(char *str);
int    my_strlcat(char *dest, char *src, int n);
int	my_strlen(char *str);
char    *my_strlowcase(char *str);
char    *my_strncat(char *dest, char *src, int n);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int n);
char	*my_strstr(char *str, char *to_find);
int     is_alnum(char c);
int	word_count(char *str);
char	**my_str_to_wordtab(char *str);
char	*my_strupcase(char *str);
int	my_swap(int *a, int *b);
int	is_alpha(char c);
char            find_intab(char c);
int             my_printf(const char *format, ...);
int             opt_d(va_list *ap, const char *format);
int             opt_s(va_list *ap, const char *format);
int             opt_c(va_list *ap, const char *format);
int             opt_x(va_list *ap, const char *format);
int             opt_X(va_list *ap, const char *format);
int             opt_o(va_list *ap, const char *format);
int             opt_u(va_list *ap, const char *format);
int             opt_b(va_list *ap, const char *format);
int             opt_S(va_list *ap, const char *format);
int             opt_mod(va_list *ap, const char *format);
int             opt_p(va_list *ap, const char *format);
int             opt_less(const char *format, int i);
int             opt_pres(const char *format, int i);
int             my_putnbr_base(int nbr, char *base);
void		*init_tab_func(void);
int             my_putnbrul_base(unsigned long int nbr, char *base);
int             error(const char *format);
int             put_oct(char c);
int		opt(const char *format, int *i, int *cont, va_list *ap);
int		isnum(char c);
int	my_putul_nbr(unsigned long int nbr, char *base);
int	my_putnbr_int_base(int nbr, char *base);
char	my_swap_char(char *a, char *b);
int	my_is_instr(char c, char *str);
int	my_count_word(char *str, char *delim);
char	**my_strtok(char *str, char *delim);
char    *add_char_to_begin(char *str, char c);

#define SYNTAX_MSG_ERROR        "\033[1;31mError\033[0m"
#define SYNTAX_USAGE_ERROR      "\033[1;31mUsage\033[0m"

#define EXIT_SUCCESS    0
#define EXIT_FAILURE    1

void    my_merror(void);
void    my_free_tab(char **tab);
int	my_puterror(char *str);

char    **my_str_to_tab(char *str, char *bdd);
char    *my_malloc(int size);

int     check_base(char c, char *bdd);

#endif
