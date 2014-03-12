/*
** parse_option1.c for parse_option1 in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat May  5 15:29:52 2012 harold ozouf
** Last update Sat Jun  2 09:20:57 2012 jordan vanwalleghem
*/

#include        <stdio.h>
#include	<unistd.h>

#include	"parse.h"
#include	"aff.h"
#include	"parse_option.h"
#include	"my.h"

int	parse_wait(t_info *inf, char **tab, int *i)
{
  static int	present;

  if (tab[*i] && !my_strcmp("-w", tab[*i]))
    {
      if (present)
	return (-1);
      if (tab[(*i) + 1] && tab[(*i) + 1][0] != '-')
	{
	  NORMAL->wait = my_getnbr(tab[(*i) + 1]);
	  (*i)++;
	}
      (*i)++;
      present++;
      return (1);
    }
  return (0);
}

int	parse_verbose(t_info *inf, char **tab, int *i)
{
  static int	present;

  if (tab[*i] && !my_strcmp("-v", tab[*i]))
    {
      if (present)
	return (-1);
      NORMAL->verbose = 1;
      (*i)++;
      present++;
      return (1);
    }
  return (0);
}

int	parse_export(t_info *inf, char **tab, int *i)
{
  static int	present;

  if (tab[*i] && !my_strcmp("-e", tab[*i]))
    {
      if (present)
	return (-1);
      if (tab[(*i) + 1] && tab[(*i) + 1][0] != '-')
	{
	  NORMAL->exp = my_strdup(tab[(*i) + 1]);
	  (*i)++;
	}
      else
	NORMAL->exp = my_strdup("file.bmp");
      (*i)++;
      present++;
      return (1);
    }
  return (0);
}

int	parse_thread(t_info *inf, char **tab, int *i)
{
  static int	present;

  if (tab[*i] && !my_strcmp("-t", tab[*i]))
    {
      if (present)
	return (-1);
      inf->nbr_thread = (tab[(*i) + 1]) ? my_getnbr(tab[++(*i)]) : \
	(sysconf(_SC_NPROCESSORS_CONF));
      inf->nbr_thread = (inf->nbr_thread <= 0) ? 1 : inf->nbr_thread;
      (*i) += 1;
      present++;
      return (1);
    }
  return (0);
}
