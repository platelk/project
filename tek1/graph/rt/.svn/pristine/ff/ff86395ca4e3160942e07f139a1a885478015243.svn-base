/*
** parse_option_n.c for parse_option_n in /home/jordan/Projets/debug_rt/rt/src
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Sat Jun  2 09:20:42 2012 jordan vanwalleghem
** Last update Sat Jun  2 09:20:45 2012 jordan vanwalleghem
*/

#include        <stdio.h>
#include        <unistd.h>

#include        "parse.h"
#include        "aff.h"
#include        "parse_option.h"
#include        "my.h"

int     parse_file(t_info *inf, char **argv, int *i)
{
  static int    present;

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

int     parse_mute(t_info *inf, char **tab, int *i)
{
  static int    present;

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
