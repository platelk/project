/*
** my.h for my in /home/leprov_a//bdd/include
**
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
**
** Started on  Thu Oct 13 11:43:31 2011 alexis leprovost
** Last update Fri Apr  6 17:33:07 2012 alexis leprovost
*/

#ifndef	__MY_H__
#define	__MY_H__

#define	ABS(value)	((value) < 0 ? (value) * (-1) : (value))

typedef enum
{
  TOK_DELIM,
  TOK_BASE
}e_type;

int	my_putnbr_base(int nbr, char *base);
int	my_getnbr_base(char *str, char *base);

int	my_power_rec(int nb, int power);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);

void	my_putchar(char c);
int	my_puterror(char *str);
void	my_putstr(char *str);

char	**my_strtok(char *str, char *bdd, int flag);
char	*my_strdup(char *expr);
char	*my_strcat(char *dest, char *src);

int	check_base(char c, char *base);
int	my_getnbr(char *str);

#endif
