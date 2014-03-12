/*
** parse_client.c for parse_client in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  2 16:17:38 2012 harold ozouf
** Last update Sat Jun  2 00:24:38 2012 ronan guiho
*/

#include	<stdlib.h>

#include	"parse_ip.h"
#include	"parse_option.h"
#include	"aff.h"
#include	"parse.h"
#include	"my.h"

static void	get_ptr_client(t_pt_funct_parse *pt)
{
  pt[0] = &parse_ip;
  pt[1] = &parse_thread;
  pt[2] = &parse_port;
  pt[3] = &parse_file;
}

static void	init_client(t_info *inf)
{
  if ((inf->arg = xmalloc(sizeof(t_client_info))) == NULL)
    exit(EXIT_FAILURE);
  CLIENT->ip_server = get_localhost();
  CLIENT->hostname = my_strdup("127.0.0.1");
  inf->nbr_thread = 1;
  inf->port = 2121;
  inf->type = TYPE_CLIENT;
}

int	parse_client(t_info *inf, char **tab, int *i)
{
  t_pt_funct_parse	pt[4];
  int			j;
  int			res;
  int			done;

  done = 0;
  get_ptr_client(pt);
  if (tab[*i] && !my_strcmp("--client", tab[*i]))
    {
      init_client(inf);
      (*i)++;
      while (!done && tab[*i])
	{
	  j = -1;
	  while (++j < 4)
	    {
	      if ((res = pt[j](inf, tab, i)) == -1)
		return (-1);
	      j = (res) ? (4) : (j);
      	    }
	  done = (res == 0 && j == 4) ? (1) : (0);
	}
      return ((!tab[*i]) ? (1) : (-1));
    }
  return (0);
}
