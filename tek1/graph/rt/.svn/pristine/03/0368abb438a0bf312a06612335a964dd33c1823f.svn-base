/*
** parse_server.c for parse_server.c in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  2 18:13:17 2012 harold ozouf
** Last update Sat Jun  2 00:27:14 2012 ronan guiho
*/

#include	"parse_normal.h"
#include	"parse_option.h"
#include	"parse_ip.h"
#include	"parse.h"
#include	"init.h"
#include	"my.h"

static void	get_ptr_server(t_pt_funct_parse *pt)
{
  pt[0] = &parse_mute;
  pt[1] = &parse_verbose;
  pt[2] = &parse_wait;
  pt[3] = &parse_export;
  pt[4] = &parse_port;
  pt[5] = &parse_file;
}

static void	init_server(t_info *inf)
{
  init_normal(inf);
  inf->type = TYPE_SERVER;
  inf->port = 2121;
  inf->nbr_thread = 1;
}

int	parse_server(t_info *inf, char **tab, int *i)
{
  int			j;
  int			res;
  t_pt_funct_parse	pt[6];
  int			done;

  done = 0;
  get_ptr_server(pt);
  if (tab[*i] && !my_strcmp("--server", tab[*i]))
    {
      init_server(inf);
      (*i)++;
      while (!done && tab[*i])
	{
	  j = -1;
	  while (++j < 6)
	    {
	      if ((res = pt[j](inf, tab, i)) == -1)
		return (-1);
	      j = (res) ? (6) : (j);
	    }
	  done = (res == 0 && j == 5) ? (1) : (0);
	}
      return ((!tab[*i]) ? (1) : (-1));
    }
  return (0);
}
