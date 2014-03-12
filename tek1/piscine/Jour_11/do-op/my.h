/*
** my.h for my.h in /home/platel_k//projet/piscine/Jour_09
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Oct 13 10:50:00 2011 kevin platel
** Last update Mon Oct 24 12:03:52 2011 kevin platel
*/

#ifndef __MY_H__
#define __MY_H__

int     my_nbr_malloc(int nbr, char *base, int c);
char     *my_nbr_base(int nbr, char *base, char *new, int c);
char	*convert_base(char *nbr, char *base_from, char *base_to);
int	my_factorielle_rec(int nb);
int	my_find_prime_sup(int nbr);
int	my_nbr(char *str,int c);
int	my_getnbr(char *str);
int	my_is_prime(int nbr);
int	my_power_rec(int nb, int power);
void	my_putchar(char c);
int	my_putnbr_base(int nbr, char *base);
int	my_put_nbr(int nbr);
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
char    *my_strlcat(char *dest, char *src, int n);
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

#endif
