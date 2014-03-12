/*
** parse.h for parse in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  2 13:09:27 2012 harold ozouf
** Last update Mon May  7 00:19:52 2012 alexis leprovost
*/

#ifndef		__PARSE_H__
# define	__PARSE_H__

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
} t_client_info;

typedef	struct	s_normal_info
{
  int		mute;
  int		verbose;
  char		*exp;
} t_normal_info;

typedef   int	(*t_pt_funct_parse)(t_info *inf, char **tab, int *i);

#define	TYPE_SERVER	0
#define	TYPE_CLIENT	1
#define	TYPE_NORMAL	2

#define	CLIENT	 ((t_client_info *)inf->arg)
#define	NORMAL	 ((t_normal_info *)inf->arg)

int	get_cmd_line(int argc, char **argv, t_info *inf);

#endif
