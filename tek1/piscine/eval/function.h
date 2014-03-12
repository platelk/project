/*
** function.h for function in /home/platel_k//projet/piscine/Jour_11/do-op
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Mon Oct 24 11:35:04 2011 kevin platel
** Last update Fri Oct 28 15:53:50 2011 kevin platel
*/

#ifndef __FUNCTION_H__
#define __FUNCTION_H__

#include "list.h"

int	add(int a, int b);
int	sub(int a, int b);
int	mul(int a, int b);
int	divis(int a, int b);
int	mod(int a, int b);
t_list          *del_one_in_list(t_list **list);
t_list          *add_in_list(t_list **list, char value);
void		my_putchar(char a);
void		my_show_list(t_list *list);
int		my_is_num(char c);
t_list		*init_list(t_list **begin);
t_list		*take_nb(t_list **begin);
int		calc(t_list **begin);

#endif
