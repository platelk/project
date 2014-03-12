/*
** xopen.c for my in /home/leprov_a//depot/42sh/src/config/lib
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun Apr 15 20:25:25 2012 alexis leprovost
** Last update Wed Apr 18 11:46:59 2012 alexis leprovost
*/

#include	"xsys.h"

int	xopen(const char *pathname, int status, int flags, t_print bool)
{
  int	fd;
  int	errno;

  errno = 0;
  if (flags)
    fd = open(pathname, status, flags);
  else
    fd = open(pathname, status);
  if (fd == -1 && bool)
    {
      if (errno == EACCES)
	fprintf(stderr, "%s: Permission denied.\n", pathname);
      else if (errno == ENOENT)
	fprintf(stderr, "%s: No such file or directory.\n", pathname);
      else if (errno == EISDIR)
	fprintf(stderr, "%s: Is a directory.\n", pathname);
      else
	fprintf(stderr, "%s: File non-existent.\n", pathname);
    }
  return (fd);
}
