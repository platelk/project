/*
** parse_ip.c for parse_ip.c in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed May  2 13:26:32 2012 harold ozouf
** Last update Fri May 25 15:00:49 2012 harold ozouf
*/

#include	<stdlib.h>

#include	"my_strtok.h"
#include	"aff.h"
#include	"put_error.h"
#include	"parse.h"
#include	"parse_ip.h"

static	int	check_nbr_elm_ip(char **values)
{
  int	i;

  i = -1;
  while (values[++i])
    if (is_a_number(values[i]))
      return (0);
  if (i == 4)
    return (1);
  return (0);
}

t_ip	*get_localhost(void)
{
  t_ip	*res;

  if ((res = xmalloc(sizeof(*res))) == NULL)
    exit(EXIT_FAILURE);
  res->octet[0] = 127;
  res->octet[1] = 0;
  res->octet[2] = 0;
  res->octet[3] = 1;
  return (res);
}

static t_ip	*get_ip(char *ip)
{
  int	i;
  t_ip	*res;
  char	**values;

  i = -1;
  values = my_strtok(ip, ".", TOK_DELIM);
  if (check_nbr_elm_ip(values))
    {
      if ((res = xmalloc(sizeof(*res))) == NULL)
	exit(EXIT_FAILURE);
      while (++i < 4)
	{
	  res->octet[i] = my_getnbr(values[i]);
	  if (!(res->octet[i] >= 0 && res->octet[i] <= 255))
	    return (NULL);
	}
      return (res);
    }
  return (NULL);
}

int	parse_port(t_info *inf, char **tab, int *i)
{
  static int	present;

  if (!present && tab[*i] && !my_strcmp("-p", tab[*i]))
    {
      present++;
      if (tab[(*i) + 1])
	{
	  inf->port = my_getnbr(tab[(*i) + 1]);
	  (*i) += 2;
	  return (1);
	}
      else
	put_error(NO_VALUE, "-p");
    }
  return (0);
}

int	parse_ip(t_info *inf, char **tab, int *i)
{
  static int	present;

  t_ip	*ip;

  if (!present && tab[*i] && !my_strcmp("-i", tab[*i]))
    {
      present++;
      if (tab[(*i) + 1] && (ip = get_ip(tab[(*i) + 1])))
	{
	  ((t_client_info *)inf->arg)->hostname = my_strdup(tab[(*i) + 1]);
	  (*i)++;
	  free(((t_client_info *)inf->arg)->ip_server);
	  ((t_client_info *)inf->arg)->ip_server = ip;
	  (*i)++;
	  return (1);
	}
      else
	return (put_error(BAD_IP, NULL));
    }
  return (0);
}
