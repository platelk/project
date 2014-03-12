/*
** xmalloc.c for xsys in /home/leprov_a//depot/42sh/src/config/lib
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun Apr 15 21:09:24 2012 alexis leprovost
** Last update Mon Apr 16 12:26:13 2012 alexis leprovost
*/

#include	"xsys.h"

void	*xmalloc(size_t size)
{
  void	*ptr;

  if ((ptr = malloc(size)) == NULL)
    {
      fprintf(stderr, "Malloc: Could not alloc.\n");
      return (NULL);
    }
  bzero(ptr, size);
  return (ptr);
}
