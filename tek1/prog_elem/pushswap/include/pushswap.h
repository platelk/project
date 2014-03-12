/*
** pushswap.h for pushswap.h in /home/platel_k/projet/pushswap/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Dec 19 13:33:49 2011 kevin platel
** Last update Sun Jan  8 11:44:34 2012 kevin platel
*/

#ifndef	__PUSHSWAP_H__
#define __PUSHSWAP_H__

typedef struct s_nbr
{
  int		nbr;
  struct s_nbr  *next;
  struct s_nbr  *prev;
} t_nbr;

void	empty_the_list(t_nbr **list_b, t_nbr **list_a);
int	init_sort(t_nbr **list_a);
void	rra(t_nbr **list_a);
void	rrb(t_nbr **list_b);
void	rrr(t_nbr **list_a, t_nbr **list_b);
t_nbr	*add_in_list(int nbr, t_nbr *begin);
t_nbr	*sa(t_nbr *list);
t_nbr	*sb(t_nbr *list);
void	ss(t_nbr **list_a, t_nbr **list_b);
void	pa(t_nbr **list_a, t_nbr **list_b);
void	pb(t_nbr **list_a, t_nbr **list_b);
void    ra(t_nbr **list_a);
void    rb(t_nbr **list_b);
void	rr(t_nbr **list_b, t_nbr **list_a);
t_nbr   *create_list(int ac, char **av);
void	aff_list(t_nbr *list_a, t_nbr *list_b);
int	select_pivot(t_nbr *list, int ac, int pivot);
int	end_of_sort(t_nbr *list_a);
int	nothing_less(int val, t_nbr *list);
void	restart(t_nbr **list_a, t_nbr **list_b);
int	init_sort_list_b(t_nbr **list_b);
void	main_function_sort(t_nbr *list_a, t_nbr *list_b);
int	val_of_end(t_nbr *list);
t_nbr   *del_one(t_nbr *list);
int	calc_moy(t_nbr *list);
void	sort_list_b(t_nbr **list_a, t_nbr **list_b, int piv);
void	sort_list_a(t_nbr **list_a, t_nbr **list_b, int piv);
int	moy_val(int nb1, int nb2, int nb3);
int	choice_val(t_nbr *list);

#endif
