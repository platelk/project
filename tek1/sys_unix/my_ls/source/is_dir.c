/*
** is_dir.c for is_dir in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Nov 29 15:10:05 2011 kevin platel
** Last update Thu Dec  1 16:25:59 2011 kevin platel
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

char	*link_of_file(char *link, t_data *directory)
{
  char		*link_file;

  link_file = malloc(my_strlen(link) + my_strlen(directory->name) + 2);
  link_file[0] = '\0';
  my_strcat(link_file, link);
  if (my_strcmp(link, "/") != 0)
    my_strcat(link_file, "/");
  my_strcat(link_file, directory->name);
  return (link_file);
}

int	is_dir(t_data *directory, char *link)
{
  struct stat	info;
  char		*link_file;

  link_file = link_of_file(link, directory);
  if ((lstat(link_file, &info)) == -1)
    {
      perror("lstat");
      exit (0);
    }
  if (S_ISDIR(info.st_mode))
    return (1);
  return (-1);
}
