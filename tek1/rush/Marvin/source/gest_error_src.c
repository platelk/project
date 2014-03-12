/*
** gest_error_src.c for gest_error_src in /home/desoul_b//rush/Marvin
** 
** Made by benoit desoulle
** Login   <desoul_b@epitech.net>
** 
** Started on  Sat Nov 26 16:14:08 2011 benoit desoulle
** Last update Sun Nov 27 10:29:55 2011 kevin platel
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "marvin.h"

int     par(char *str)
{
  int   i;
  int   count;
  int	neg;

  i = 0;
  count = 0;
  neg = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '(')
	count = count + 1;
      else if (str[i] == ')')
	neg = neg + 1;
      i++;
    }
  if ((count - neg) < 0)
    my_printf("Erreur : %d parenthèse(s) fermante(s) en trop.\n", neg);
  else if ((count - neg) > 0)
    my_printf("Erreur : %d parenthèse(s) ouvrante(s) en trop.\n", count);
  if ((count - neg) != 0)
    return (1);
  return (0);
}

int	abs(int i)
{
  if (i < 0)
    i = i * -1;
  return (i);
}

void     hook(char *str)
{
  int   i;
  int   count;
  int	neg;

  i = -1;
  count = 0;
  neg = 0;
  while (str[++i])
    {
      if (str[i] == '[')
	count = count + 1;
      else if (str[i] == ']')
	{
	  count = count - 1;
	  neg = neg + 1;
	}
    }
  if (count < 0)
    printf("Erreur : %d crochet(s) fermant en trop.\n", neg);
  else if (count > 0)
    printf("Erreur : %d crochet(s) ouvrant en trop.\n", count);
  if (count != 0)
    exit(1);
}

int     semicolon(char *str)
{
  int   i;

  i = -1;
  while (str[++i]);
  if (str[i - 1] != ';')
    {
      printf("Erreur : point-virgules mal placé\n");
      return (1);
    }
  return (0);
}
