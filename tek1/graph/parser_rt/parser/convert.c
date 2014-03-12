/*
** convert.c for coonvert in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Thu Feb 16 11:47:40 2012 harold ozouf
** Last update Mon Mar  5 22:17:48 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"xfnt.h"
#include	"aff.h"
#include	"convert.h"

int     my_pow(int x, int pow)
{
  int   res;

  res = 1;
  while (--pow >= 0)
    res *= x;
  return (res);
}

int	to_int(char *str)
{
  int   pos;
  int   signe;
  int   nbr;

  signe = 1;
  pos = -1;
  while (str[++pos] != '\0' && (str[pos] == '+' || str[pos] == '-'))
    if (str[pos] == '-')
      signe = signe * -1;
  str += pos;
  nbr = 0;
  pos = -1;
  while (str[++pos] >= '0' && str[pos] <= '9')
    {
      nbr *= 10;
      nbr -= str[pos] - '0';
    }
  return (nbr * signe * -1);
}

double	to_double(char *str)
{
  int		i;
  int		j;
  int		x;
  double	res;
  char		*nbr;

  i = -1;
  j = -1;
  x = -1;
  nbr = xmalloc(sizeof(*nbr) * (my_strlen(str) + 1));
  while (str[++i])
    if (str[i] == '.')
      if (x == -1)
	x = i;
      else
	xexit("Error bad floating number");
      else
	nbr[++j] = str[i];
  nbr[++j] = '\0';
  if (x == -1)
    res = (double)to_int(nbr);
 else
   res = (double)to_int(nbr) / (double)my_pow(10, (my_strlen(str) - (x + 1)));
  free(nbr);
  return (res);
}
