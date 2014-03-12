/*
** xfnt.c for xfnt in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 15:51:07 2012 harold ozouf
** Last update Fri Feb 17 23:07:21 2012 harold ozouf
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<unistd.h>
#include	<fcntl.h>
#include	<stdlib.h>
#include	"aff.h"
#include	"xfnt.h"

void	xerror(char *name, char *msg)
{
  write(1, "Error: ", 7);
  write(1, name, my_strlen(name));
  my_putchar(' ');
  write(1, msg, my_strlen(msg));
  my_putchar('\n');
  exit(0);
}

void    xexit(char *str)
{
  write(2, str, my_strlen(str));
  exit(0);
}

void	*xmalloc(int size)
{
  void	*mal;

  mal = malloc(size);
  if (mal == NULL)
    xexit("Error : could not malloc.\n");
  return (mal);
}

void	*xrealloc(char *str, int size)
{
  str = realloc(str, size);
  if (str == NULL)
    xexit("Error : could not realloc.\n");
  return (str);
}

int	xopen(char *str, int flags)
{
  int	fd;

  fd = open(str, flags);
  if (fd == -1)
    xexit("Error : could not open\n");
  return (fd);
}
