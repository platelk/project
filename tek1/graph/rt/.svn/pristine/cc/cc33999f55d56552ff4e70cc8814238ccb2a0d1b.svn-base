/*
** parse_normal.c for parse_normal in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  2 15:16:14 2012 harold ozouf
** Last update Sat Jun  2 00:35:27 2012 ronan guiho
*/

#include	<unistd.h>
#include	<stdlib.h>

#include	"parse.h"
#include	"parse_option.h"
#include	"parse_normal.h"
#include	"my.h"

void	init_normal(t_info *inf)
{
  inf->type = TYPE_NORMAL;
  if ((inf->arg = xmalloc(sizeof(t_normal_info))) == NULL)
    exit(EXIT_FAILURE);
  inf->port = 0;
  inf->nbr_thread = 1;
  NORMAL->mute = 0;
  NORMAL->verbose = 0;
  NORMAL->wait = 0;
  NORMAL->exp = NULL;
}

static void	get_ptr_normal(t_pt_funct_parse *pt)
{
  pt[0] = &parse_mute;
  pt[1] = &parse_export;
  pt[2] = &parse_verbose;
  pt[3] = &parse_thread;
  pt[4] = &parse_file;
}

int	parse_normal(t_info *inf, char **argv, int *i)
{
  int			j;
  int			res;
  t_pt_funct_parse	pt[5];
  int			done;

  done = 0;
  get_ptr_normal(pt);
  init_normal(inf);
  while (!done && argv[*i])
    {
      j = -1;
      while (++j < 5)
	{
	  if ((res = pt[j](inf, argv, i)) == -1)
	    return (-1);
	  j = (res) ? (5) : (j);
	}
      done = (res == 0 && j == 5) ? (1) : (0);
    }
  return ((argv[*i]) ? (-1) : (1));
}
