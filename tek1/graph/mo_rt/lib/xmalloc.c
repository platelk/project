/*
** xmalloc.c for xsys in /home/leprov_a//depot/42sh/src/config/lib
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun Apr 15 21:09:24 2012 alexis leprovost
** Last update Mon May  7 00:03:59 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"my.h"

void	*xmalloc(size_t size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      my_puterror("Error: Could not alloc.\n");
      return (NULL);
    }
  return (ptr);
}
