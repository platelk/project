/*
** my.h for my.h in /home/guiho_r//workhome/piscine
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Thu Oct 13 10:31:45 2011 ronan guiho
** Last update Sun May  6 17:04:36 2012 ronan guiho
*/

#ifndef __MY_H__
#define __MY_H__

int	is_number(char *str);
char	*my_strdup(char *str);
char	**my_strtok(char *str, char *bdd, int flag);
char	*my_strconcat(char *s1, char *s2);
void	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb, char *base);
void	my_swap(int *a, int *b);
void	my_putstr(char *str);
int	my_strlen(char *str);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nombre);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int nb);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, char *src);
char	*my_strncat(char *dest, char *src, int nb);
int	my_strlcat(char *dest, char *src, int size);

#endif
