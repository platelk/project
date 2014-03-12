/*
** size_tot.c for size_tot in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Nov 30 16:02:53 2011 kevin platel
** Last update Thu Dec  1 17:40:26 2011 kevin platel
*/

#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>

#include "my.h"
#include "my_ls.h"
#include "data.h"

void	size_tot(t_data *directory, char *link)
{
  struct stat	info;
  char		*link_file;
  int		size;

  size = 0;
  while (directory != NULL)
    {
      link_file = malloc(my_strlen(link) + my_strlen(directory->name) + 2);
      link_file[0] = '\0';
      my_strcat(link_file, link);
      my_strcat(link_file, "/");
      my_strcat(link_file, directory->name);
      if ((lstat(link_file, &info)) == -1)
	{
	  perror("lstat");
	  directory = NULL;
	}
      else
	{
	  size += (info.st_size / 512);
	  directory = directory->next;
	  free(link_file);
	}
    }
  my_printf("total %d\n", size);
}
