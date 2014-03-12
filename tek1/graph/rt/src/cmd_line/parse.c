/*
** parse.c for parse in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  2 18:39:49 2012 harold ozouf
** Last update Fri May 25 13:49:03 2012 ronan guiho
*/

#include	<stdlib.h>

#include	"aff.h"
#include	"parse_server.h"
#include	"parse_client.h"
#include	"parse_normal.h"
#include	"parse.h"
#include	"my.h"

static int	parse(char **argv, t_info *inf)
{
  int	i;
  int	res_s;
  int	res_c;
  int	res_n;

  i = 1;
  res_s = 0;
  res_c = 0;
  res_n = 0;
  if ((res_s = parse_server(inf, argv, &i)) == 0)
    if ((res_c = parse_client(inf, argv, &i)) == 0)
      res_n = parse_normal(inf, argv, &i);
  return ((res_c == -1 || res_s == -1 || res_n == -1) ? (-1) : (1));
}

int	get_cmd_line(int argc, char **argv, t_info *inf)
{
  inf->xml = NULL;
  if (argc > 1)
    {
      if (argv[1] && !my_strcmp("--help", argv[1]))
	{
	  print_usage();
	  return (0);
	}
      else if (parse(argv, inf) == 1 && inf->xml != NULL)
	return (1);
    }
  my_putstr("Error: use --help for the HOW TO\n");
  return (0);
}
