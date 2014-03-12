/*
** put_error.c for put_error in /home/ozouf_h//rt_parse
** 
** Made by harold ozouf
** Login   <ozouf_h@epitech.net>
** 
** Started on  Sat May  5 14:41:01 2012 harold ozouf
** Last update Sat Jun  2 09:19:39 2012 jordan vanwalleghem
*/

#include	"aff.h"
#include	"put_error.h"
#include	"my.h"

int	put_error(char *msg, char *value)
{
  my_putstr("Error: ");
  my_putstr(msg);
  my_putchar(' ');
  if (value)
    my_putstr(value);
  my_putstr(".\n");
  return (-1);
}
