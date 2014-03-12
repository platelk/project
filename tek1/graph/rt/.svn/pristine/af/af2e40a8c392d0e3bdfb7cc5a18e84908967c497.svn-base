/*
** parse_option1.c for parse_option1 in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat May  5 15:29:52 2012 harold ozouf
** Last update Fri May 25 14:12:54 2012 ronan guiho
*/

#include        <stdio.h>
#include	<unistd.h>

#include	"parse.h"
#include	"aff.h"
#include	"parse_option.h"
#include	"my.h"

int	parse_file(t_info *inf, char **argv, int *i)
{
  static int	present;

  if (argv[*i])
    {
      if (present)
	return (-1);
      inf->xml = my_strdup(argv[*i]);
      *i += 1;
      present++;
      return (1);
    }
  return (0);
}

int	parse_mute(t_info *inf, char **tab, int *i)
{
  static int	present;


  if (tab[*i] && !my_strcmp("-m", tab[*i]))
    {
      if (present)
	return (-1);
      NORMAL->mute = 1;
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
