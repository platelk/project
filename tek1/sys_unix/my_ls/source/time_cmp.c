/*
** time_cmp.c for time_cmp in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Nov 29 13:09:36 2011 kevin platel
** Last update Thu Dec  1 12:19:00 2011 kevin platel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "data.h"
#include "my.h"
#include "my_ls.h"

int	time_file(t_data *directory, char *link)
{
  struct stat	info;
  char		*link_file;

  link_file = malloc(my_strlen(link) + my_strlen(directory->name) + 2);
  link_file[0] = '\0';
  my_strcat(link_file, link);
  my_strcat(link_file, "/");
  my_strcat(link_file, directory->name);
  if ((lstat(link_file, &info)) == -1)
    exit(0);

  return (info.st_mtime);
}

int		my_sort_list_time(t_data **begin, char *link)
{
  if ((*begin) != NULL)
    {
      while ((*begin)->next != NULL)
	if ((time_file((*begin), link) - time_file((*begin)->next, link)) < 0)
	  {
	    my_list_swap((*begin));
	    while ((*begin)->prev != NULL)
	      (*begin) = (*begin)->prev;
	  }
	else
	  (*begin) = (*begin)->next;
      while ((*begin)->prev != NULL)
	(*begin) = (*begin)->prev;
    }
  return (0);
}
