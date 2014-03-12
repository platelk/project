/*
** my.h for my in /home/przyby_m/include/my.h
**
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
**                  
** Started on at Oct 29 19:22:09 2011 matthieu przybylski
** Last update at Oct 29 19:22:09 2011 matthieu przybylski
*/

#ifndef __MY_H__
#define __MY_H__

int	my_strchar(char *str, char to_find);
char	*joker(char *s1, char *s2, int i);
int	verify_again(char *s1, char *new_s2);
int	match(char *s1, char *s2);
char	*trad_base_from(char *nbr, char *base);
char    *trad_base_to(char *nbr, char *base);
int	test_malloc(int number_test, int base);
char	*convert_base_10toN(char *nbr, int number, char *base_to);
char	*convert_base(char *nbr, char *base_from, char *base_to);
int     my_find_prime_sup(int nb);
int	error_int(char *str, int i);
int	nbr_less(char *str);
int	my_getnbr(char *str);
int	my_isneg(int nb);
int	my_is_prime(int nb);
int	my_power_rec(int nb, int power);
void my_putchar(char c);
int	count_nbr(int nbr);
void	my_putnbr(int nbr);
void	my_putstr(char *str);
void     my_swap_bis(char *a, char *b);
char    *my_revstr(char *str);
int     my_show_wordtab(char **tab);
void	my_sort_int_tab(int *tab, int size);
int	my_square_root(int nb);
char    *my_strcapitalize(char *str);
char *my_strcat(char *dest, char *src);
int     my_strcmp(char *s1, char *s2);
char	*my_strcpy(char *dest, char *src);
char	*my_strdup(char *src);
int    my_str_isalpha(char *str);
int    my_str_islower(char *str);
int    my_str_isnum(char *str);
int    my_str_isprintable(char *str);
int	my_str_isupper(char *str);
int my_strlcat(char *dest, char *src, int size);
int	my_strlen(char *str);
char	*my_strlowcase(char *str);
char *my_strncat(char *dest, char *src, int n);
int     my_strncmp(char *s1, char *s2, int n);
char	*my_strncpy(char *dest, char *src, int n);
int	loop(char *str, char* to_find, int j, int i);
char	*my_strstr(char *str, char *to_find);
int     char_alphanum(char c);
int     count_word(char *str);
char	*find_word(char *str, int *ptr_j);
char	**my_str_to_wordtab(char *str);
char	*my_strupcase(char *str);
void	my_swap(int *a, int *b);

#endif
