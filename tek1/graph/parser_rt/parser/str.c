/*
** str.c for str in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 09:41:52 2012 harold ozouf
** Last update Sun Mar 11 14:56:54 2012 harold ozouf
*/

#include	<stdlib.h>
#include	"aff.h"
#include	"xfnt.h"
#include	"str.h"

char	*my_strcat(char *str, char *concat)
{
  char	*res;
  int	i;
  int	j;

  i = -1;
  j = -1;
  res = xmalloc(sizeof(*res) * (my_strlen(str) + my_strlen(concat) + 1));
  if (res != NULL)
    {
      while (str[++i])
	res[i] = str[i];
      while (concat[++j])
	res[j + i] = concat[j];
      res[j + i] = '\0';
      free(str);
      return (res);
    }
  return (NULL);
}

char	*my_strdup(char *src)
{
  int   i;
  char	*cpy;

  i = 0;
  cpy = xmalloc(sizeof(*src) * (my_strlen(src) + 1));
  while (src[i])
    {
      cpy[i] = src[i];
      i = i + 1;
    }
  cpy[i] = '\0';
  return (cpy);
}

int	my_strcmp(char *src, char *search)
{
  int	i;

  i = -1;
  while (src[++i] && search[i])
    if (src[i] != search[i])
      return (1);
  return (0);
}

char    *my_strcut(char *str, int cut)
{
  int   i;
  char  *new;

  if (cut >= my_strlen(str))
    return (str);
  new = xmalloc(sizeof(*new) * (cut + 1));
  i = 0;
  while (i < cut)
    {
      new[i] = str[i];
      i = i + 1;
    }
  new[i] = '\0';
  return (new);
}

int	my_strncmp(char *sek, char *cntr, int size)
{
  int	i;

  i = -1;
  while (++i < size && cntr[i])
    if (sek[i] != cntr[i])
      return (1);
  if (i == size)
    return (0);
  return (1);
}
