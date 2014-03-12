/*
** printf.h for my_printf in /home/platel_k/projet/my_printf
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Fri Nov 11 12:57:27 2011 kevin platel
** Last update Fri Nov 18 14:57:27 2011 kevin platel
*/

#ifndef __PRINTF_H__
#define __PRINTF_H__

char		find_intab(char c);
int		my_printf(const char *format, ...);
int		opt_d(va_list *ap,const char *format);
int		opt_s(va_list *ap,const char *format);
int		opt_c(va_list *ap, const char *format);
int		opt_x(va_list *ap, const char *format);
int		opt_X(va_list *ap, const char *format);
int		opt_o(va_list *ap, const char *format);
int		opt_u(va_list *ap, const char *format);
int		opt_b(va_list *ap, const char *format);
int		opt_S(va_list *ap, const char *format);
int		opt_mod(va_list *ap, const char *format);
int		opt_p(va_list *ap, const char *format);
int		opt_less(char *format, int i);
int		opt_pres(char *format, int i);
int		my_putnbr_base(int nbr, char *base);
int		init_tab_func();
int		my_putnbrul_base(unsigned long int nbr, char *base);
int		error(char *format);
int		put_oct(char c);
int	opt(const char *format, int *i, int *cont, va_list *ap);

#endif
