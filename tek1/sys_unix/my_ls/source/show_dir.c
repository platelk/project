/*
** show_dir.c for show_dir in /home/platel_k/projet/my_ls/source
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Tue Nov 22 20:44:16 2011 kevin platel
** Last update Mon Dec 12 21:36:14 2011 kevin platel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "data.h"
#include "my.h"
#include "my_ls.h"

void	aff_ls(t_data *direc, int opt, char *link, t_data **dir)
{
  while (direc != NULL)
    {
      (opt & 1) == 1 ? listing(direc, link, opt) : my_printf("%s  ", NAME_DIR);
      if ((opt & 2) != 2)
	direc = del_in_list(direc);
      else
	{
	  if (is_dir(direc, link) == 1 && IS_POINT)
	    (*dir) = add_new(dir, direc->name);
	  direc = del_in_list(direc);
	}
    }
}

int	show_dir(char *link, int opt)
{
  t_data	*directory;
  t_data	*dir;
  DIR		*dir_op;

  dir_op = NULL;
  directory = get_data(link, opt, &dir_op);
  dir = NULL;
  if ((opt & 1) == 1)
    size_tot(directory, link);
  aff_ls(directory, opt, link, &dir);
  while (dir != NULL && dir->next != NULL)
    dir = dir->next;
  while (dir != NULL)
    {
      my_printf("\n%s:\n", link_of_file(link, dir));
      show_dir((link_of_file(link, dir)), opt);
      dir = del_in_list(dir);
    }
  closedir(dir_op);
  return (0);
}

t_data		*get_data(char *link, int opt, DIR **dir)
{
  struct	dirent	*fichier;
  t_data	*directory;

  directory = NULL;
  if ((opt & 16) == 16)
    directory = add_new(&directory, link);
  else
    if ((*dir = opendir(link)) == NULL)
      perror("opendir");
    else
      {
	while ((fichier = readdir(*dir)))
	  if (fichier->d_name[0] != '.')
	    directory = add_new(&directory, fichier->d_name);
	  else if (fichier->d_name[0] == '.' && (opt & 64) == 64)
	    directory = add_new(&directory, fichier->d_name);
	if (directory == NULL)
	  return (NULL);
	(opt & 8) == 8 ? my_sort_list_time(&directory, link) :
	  my_sort_list(&directory, &my_sort_by_alpha);
	if ((opt & 4) == 4)
	  rev_list(&directory);
      }
  return (directory);
}
