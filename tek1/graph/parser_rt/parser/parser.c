/*
** parser.c for parser in /home/ozouf_h//projet/rtv1/parser/srcs
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Wed Feb 15 15:50:49 2012 harold ozouf
** Last update Tue May  1 10:30:31 2012 kevin platel
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<sys/types.h>
#include	<sys/stat.h>
#include	<fcntl.h>
#include	"my.h"
#include	"str.h"
#include	"xfnt.h"
#include	"parser.h"

char    *parser(char *path)
{
  char  *parse;
  char  buffer[READ + 1];
  int   ret;
  int   fd;

  parse = NULL;
  fd = xopen(path, O_RDONLY);
  while ((ret = read(fd, buffer, READ)) > 0)
    {
      buffer[ret] = '\0';
      if (parse == NULL)
	parse = my_strdup(buffer);
      else
	parse = my_strmcat(parse, buffer);
    }
  if (ret == -1)
   xexit("Error: could not read\n");
  close(fd);
  return (parse);
}
