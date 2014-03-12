/*
** parse.h for parse in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  2 13:09:27 2012 harold ozouf
** Last update Sat Jun  2 00:22:47 2012 ronan guiho
*/

#ifndef		__PARSE_H__
#define		__PARSE_H__

#define	NB_MAIN_OPTION	3

typedef	struct s_pt
{
  int	x;
  int	y;
} t_pt;

typedef	struct	s_ip
{
  int	octet[4];
} t_ip;

typedef	struct	s_info
{
  int	type;
  void	*arg;
  char	*xml;
  int	port;
  int	nbr_thread;
} t_info;

typedef	struct	s_client_info
{
  t_ip	*ip_server;
  char	*hostname;
} t_client_info;

typedef	struct	s_normal_info
{
  int		mute;
  int		wait;
  int		verbose;
  char		*exp;
} t_normal_info;

typedef   int	(*t_pt_funct_parse)(t_info *, char **, int *);

typedef enum
{
  TYPE_SERVER,
  TYPE_CLIENT,
  TYPE_NORMAL
} e_type;

#define	CLIENT	 ((t_client_info *)inf->arg)
#define	NORMAL	 ((t_normal_info *)inf->arg)

int	get_cmd_line(int, char **, t_info *);

#endif
