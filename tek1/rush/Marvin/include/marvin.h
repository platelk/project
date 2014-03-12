/*
** marvin.h for marvin in /home/platel_k/projet/rush/Marvin/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov 25 21:09:51 2011 kevin platel
** Last update Sun Nov 27 13:36:25 2011 kevin platel
*/

#ifndef __MARVIN_H__
#define __MARVIN_H__

#include <stdlib.h>
#include <string.h>

void    aff_type(char *str);
int	type(char *str);
void	boucle(int j, int k, char **tab, char *str);
int	size(char *str);
int	word_count_mod(char *str);
char	**my_str_to_wordtabmod(char *str);
void	freewordtab(char ***tab);
int	detect_tab(char *str);
void	declar(char *argv);
void	find_const(char **str);
char	**my_new_str_to_wordtab(char *str);
int	word_count_hand(char *str);
int     is_alnumhand(char c);
void	main_loop(char *str, char *str2, char *str3, char *delimiter);
void	put_point_function(char *str, char *str2, char *str3);
int	error_char2(char *str);
int	error_char(char *str);
int    error_len_str(int param, char **str);
int     par(char *str);
int	abs(int i);
void     hook(char *str);
int     semicolon(char *str);

#endif
