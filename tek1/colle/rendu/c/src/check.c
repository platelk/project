/*
** check.c for colle in /home/fontai_t/colle2
** 
** Made by thomas fontaine
** Login   <fontai_t@epitech.net>
** 
** Started on  Thu Apr 26 22:21:44 2012 thomas fontaine
** Last update Thu Apr 26 23:16:34 2012 thomas fontaine
*/

#include "put.h"
#include "check.h"
#include "get.h"
#include "count.h"

#define IS_NUM(x)       (((x < '0') || (x > '9')) ? -1 : 0)

int     check_nb_args(int nb, char *cmd)
{
  if (nb != 4)
    {
      my_puterr("Use : ");
      my_puterr(cmd);
      my_puterr(" length weight \"characters\"\n");
      return (1);
    }
  return (0);
}

int     check_nbrs(char *s1, char *s2)
{
  int   i;

  i = -1;
  while (s1[++i])
    if (IS_NUM(s1[i]) == -1)
      {
        my_puterr("Error in length\n");
        return (1);
      }
  i = -1;
  while (s2[++i])
    if (IS_NUM(s2[i]) == -1)
      {
        my_puterr("Error in weight\n");
        return (1);
      }
  return (0);
}

int     check_length_nbrs(char *s1, char *s2)
{
  if (my_strlen(s1) == 0 || my_strlen(s1) > 9)
    {
      my_puterr("Error in length\n");
      return (1);
    }
  if (my_strlen(s2) == 0 || my_strlen(s2) > 9)
    {
      my_puterr("Error in weight\n");
      return (1);
    }
  return (0);
}

int     check_chars(char *str)
{
  int   i;
  int   j;
  char  c;

  if (my_strlen(str) != 4)
    {
      my_puterr("Error in chars : != 4\n");
      return (1);
    }
  i = 0;
  while (str[i])
    {
      j = i + 1;
      c = str[i];
      while (str[j])
	if (str[j++] == c)
          {
            my_puterr("Error : Same char\n");
            return (1);
          }
      i++;
    }
  return (0);
}

int     check_user(int ac, char **av)
{
  if (check_nb_args(ac, av[0]) == 1)
    return (1);
  if (check_length_nbrs(av[1], av[2]) == 1)
    return (1);
  if (check_nbrs(av[1], av[2]) == 1)
    return (1);
  if (check_chars(av[3]) == 1)
    return (1);
  return (0);
}
