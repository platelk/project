/*
** 102.h for 102 in /home/platel_k/projet/102matrice/include
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Sun Dec  4 09:21:42 2011 kevin platel
** Last update Sun Dec  4 15:44:20 2011 kevin platel
*/

#ifndef __102_H__
#define __102_H__

int	*creat_matrice(int ac, char **av, int dim, int base);
char	*get_base(int base);
int	opt_one(int ac, char **av, int base);
int	opt_two(int ac, char **av, int base);
int	verif_base(int base, char *str);

#endif
