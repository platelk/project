/*
** mastermid.h for master in /home/vink/projet/colle/src
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Thu Apr 19 14:29:17 2012 kevin platel
** Last update Thu Apr 19 15:48:09 2012 kevin platel
*/

#ifndef	__MASTER_H__
#define __MASTER_H__

int	my_putnbr(int nb);
int     my_strcmp(char *s1, char *s2);
int     my_strlen(char *str);
int	put_error_pion(char c);
char    *my_rand_code(int nb, char *piont);
int     verif_piont(char *piont);
int     check_game(char *code, char *pion, int slot, int tentative);
int     is_inpion(char *pion, char *enter);

#endif
