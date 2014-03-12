/*
** bistromathique.h for bistromathique in .
** 
** Made by Charlie Root
** Login   <rn@epita.fr>
** 
** Started on  Tue Oct 23 11:48:35 2001 Charlie Root
** Last update Thu Nov 10 09:21:50 2011 matthieu przybylski
*/

#ifndef __BISTROMATHIQUE_H__
#define __BISTROMATHIQUE_H__

#define	OP_OPEN_PARENT_IDX	0
#define	OP_CLOSE_PARENT_IDX	1
#define	OP_PLUS_IDX		2
#define	OP_SUB_IDX		3
#define	OP_NEG_IDX		3
#define OP_MULT_IDX		4
#define OP_DIV_IDX		5
#define OP_MOD_IDX		6

#define	SYNTAXE_ERROR_MSG	"syntax error\n"

int     divide_spe(t_list *nb1, t_list *nb2, char *num);
t_list	*add_before_list(t_list **list, char value);
t_list  *add_in_list(t_list **list, char value);
t_list  *add_one_in_list(t_list **list, char value);
t_list	*calc_sub(t_list *nb1, t_list *nb2, char *ref_num);
int	check_op(t_list *begin, char *num, char *op);
int	check_par(t_list *begin, char *op);
void	put_sign(t_list **list, int count, char *op, char *num);
int	decrypt(t_list **list, char *op, char *ref_num);
t_list	*del_in_list(t_list **begin, t_list **end);
t_list  *del_one_in_list(t_list **list);
int	del_par(t_list **list, char *ref_num, char *ref_op);
void	del_useless_par(t_list **list, char *ref_num, char *ref_op);
int	error(char *begin, char *num, char *op);
void    get_calc(t_list **list, char *ref_num, char *ref_op);
void	get_prio_calc(t_list **list, char *ref_num, char *ref_op);
char	*eval_expr(char *base, char *op, char *expr, unsigned int size);
int	main(int argc, char **argv);
void	go_to_end(t_list **list);
t_list	*add(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op);
t_list	*sub(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op);
t_list	*mult(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op);
t_list	*divi(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op);
int	mod(int a, int b);
t_list	*init_list(t_list **begin, char c);
t_list	*add_digit_in_list(t_list **list, char digit, int *nbr);
t_list	*int_to_list(int nbr);
int	is_empty(char *expr, char *num, char *op);
int	isnum(char c, char *ref);
int	isop(char c, char *ref);
int     int_list(t_list *list1, t_list *list2, char *ref_num);
t_list	*list_cpy(t_list *begin);
t_list	*list_ncpy(t_list *begin, int n);
int	val(char *ref_num, char c);
int	list_to_int(t_list *begin, char *ref_num, char *ref_op, int size);
int	main(int ac,char **av);
int	my_char_base(t_list *begin, char *base);
int	my_list_size(t_list *begin);
void	my_put_nbr(int nb);
void	my_putchar(char a);
void	my_show_list(t_list *list);
int	remaining_op(t_list *begin, char *ref_op);
int	remaining_op_par(t_list **begin, char *ref_op, char *ref_num);
void	put_result(t_list **list, t_list *new, char *ref_op);
t_list  *replace(t_list **list, t_list *new, char *refnum, char *ref_op);
int	signe_mult(t_list **nb1, t_list **nb2, char *ref_op);
int	synt_error(t_list *begin, char *base, char *op);
void	tab_to_list(t_list **begin, char *expr, char *ref_num, char *ref_op);
t_list	*take_nb(t_list *begin, char *ref_num);
int	val_cha(char *begin, char *ref_num,char *ref_op);
char	*list_to_tab(t_list *temp);
t_list	*del_us_zero(t_list **nb, char *base);
t_list	*concat(t_list **list, t_list **list2);
t_list	*calc(t_list *nb1, int isop, t_list *nb2, char *num, char *op);
t_list  *calc_mult(t_list *nb1, t_list *nb2, char *num, char *op);
void    signe_divi(t_list **nb1, t_list **nb2, t_list **result, char *ref_op);
t_list  *modu(t_list *nb1, t_list *nb2, char *ref_num, char *ref_op);
int     divide_spe(t_list *nb1, t_list *nb2, char *num);
int     calc_div(t_list **test,t_list *nb_cpy, char **num_op, t_list *nb2);
char    **concat_char(char *num, char *op);
void    init_nb_cpy(t_list **nb_cpy, t_list *r, t_list *nb1, char *ref_num);
void    init_div(t_list **result, t_list **r, t_list **nb2, char *ref_num);
t_list  *define_r(t_list *result, t_list *r_sub, t_list *nb_cpy, char *op);

#endif
