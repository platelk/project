/*
** gest_error.c for gest_error in /home/desoul_b//rush/Marvin
** 
** Made by benoit desoulle
** Login   <desoul_b@epitech.net>
** 
** Started on  Sat Nov 26 14:20:08 2011 benoit desoulle
** Last update Sun Nov 27 13:28:39 2011 kevin platel
*/
#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "marvin.h"

int	error_char2(char *str)
{
  int	i;
  int	count;

  i = -1;
  count = 0;
  while (str[++i])
    {
      if (str[i] < '\t' || (str[i] > '\t' && str[i] < ' ') ||   \
          (str[i] > ' ' && str[i] < '(') || (str[i] > '*' && str[i] < ',') || \
          str[i] == '-' || str[i] == '.' || str[i] == '/' || str[i] == ':' || \
          (str[i] > ';' && str[i] < 'A') || str[i] == '^' || str[i] > 'z')
	count++;
    }
  if (count > 0)
    {
      printf("%d erreur de syntaxe.\n", count);
      return (1);
    }
  return (0);
}

int	error_char(char *str)
{
  int	p;

  p = par(str) +  semicolon(str) + error_char2(str);
  hook(str);
  if (p != 0)
    exit(1);
  return (0);
}

int    error_len_str(int param, char **str)
{
  int	i;

  i = -1;
  if (param != 2)
    {
      printf("%c", '\n');
      exit(1);
    }
  if (str[1][0] == '\0')
    {
      printf("Erreur : chaîne vide.\n");
      exit(1);
    }
  while (str[1][++i] != '\0' && str[1][i] != ' ')
  if (str[1][i] == '\0')
    {
      printf("Erreur : chaîne invalide.\n");
      exit(1);
    }
  if (error_char(str[1]) != 0)
    exit(1);
  return (0);
}
