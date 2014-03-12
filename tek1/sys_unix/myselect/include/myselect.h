/*
** myselect.h for myselect in /home/platel_k/projet/sys_unix/myselect/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Thu Dec 29 17:05:16 2011 kevin platel
** Last update Tue Jan 31 15:32:15 2012 kevin platel
*/

#ifndef __MY_SELECT__
#define __MY_SELECT__

#define	ERROR	(-1)
#define TABULATION	(4)
#define SET	(1)
#define UNSET	(0)
#define UP	(65)
#define DOWN	(66)
#define LEFT	(68)
#define RIGHT	(67)
#define QUIT	('\n')
#define SELECT  (' ')
#define DELETE  (127)
#define ECHAP	(27)

#include <termios.h>
#include <signal.h>

typedef void (*sighandler_t)(int);

typedef struct s_element
{
  char	 *name;
  int	 lenght;
  int	 cursor;
  int	 is_select;
  struct s_element *next;
  struct s_element *prev;
} t_element;

typedef struct s_term
{
  int	fd;
  char	*cursor_mouv;
  char	*under_lig_start;
  char	*under_lig_end;
  char	*cursor_vi;
  char	*cursor_ve;
  char	*revers_vid;
  char	*end_mode;
  char	*clear;
} t_term;

int tgetent(char *bp, const char *name);
char *tgetstr(char *id, char **area);
int tputs(const char *str, int affcnt, int (*putc)(int));

t_element	*add_in_list(t_element *list, char *name);
t_element	*del_one_in_list(t_element *list);
void		free_list(t_element *list);
t_element	*creat_list(char **av, int ac);

int	put_c(int cap);
int	display_list(t_element *list, t_term *term);
int	put_us(char *str);
int	put_rv(char *str);
int	use_termcap(char *cap);

int	can_display_list(t_element *list, t_element *begin, t_term *term);
int	nb_col(t_term *term);
int	nb_lin(t_term *term);
t_term	*init_term_info(void);

int	free_term_info(t_term *term);
int	quit_select(t_element *list, t_term *term, int mode);
void	quit_signal(int signal);
void	winch_signal(int signal);

int	raw_mode(int mode);
int	echo_mode(int mode);
int	visible_cursor(int mode);
int	mouv_curs(int x, int y);
int	screen_clean(void);

int	get_data(t_term *term);
int	treatment_of_data(int action, t_element *list);
int	return_data(t_element *list);

int	disable_signal(void);
void	winch_signal(int signal);

int	init_select(t_element **list, t_term **term, char **av, int ac);
char	*get_term(char **envp);
int	display(t_element *list, int max_lenght);

int	raw_mode(int mode);
int	echo_mode(int mode);
int	visible_cursor(int mode);
int	mouv_curs(int x, int y);
int	screen_clean(void);

#endif
