/*
** determ_export.c for determ_export in /home/jordan/Projets/debug_rt/export
** 
** Made by jordan vanwalleghem
** Login   <vanwal_j@epitech.net>
** 
** Started on  Thu May 31 19:18:46 2012 jordan vanwalleghem
** Last update Sun Jun  3 20:10:15 2012 jordan vanwalleghem
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include "global.h"
#include "export.h"
#include "export_jpg.h"
#include "my.h"

int	determ_type_n_file_name(char *file_name, char *full_exp)
{
  int x;

  x = 0;
  while (full_exp[x])
    {
      file_name[x] = full_exp[x];
      x++;
      file_name[x] = 0;
      if (my_strcmp(&full_exp[x], ".jpeg") == 0 || \
	  my_strcmp(&full_exp[x], ".jpg") == 0)
	  return (0);
      if (my_strcmp(&full_exp[x], ".bmp") == 0)
	return (1);
    }
  return (0);
}

int	nbr_len(int nbr)
{
  int ret;

  ret = 0;
  while (nbr > 0)
    {
      nbr = nbr / 10;
      ret++;
    }
  return (ret);
}

char	*nbr_to_str(int nbr)
{
  char *ret;
  int x;
  int div;

  div = nbr_len(nbr) - 1;
  x = 0;
  if ((ret = malloc((div + 20) * sizeof(char))) == NULL)
    return (NULL);
  while (div >= 0)
    {
      ret[x] = ((nbr / my_power_rec(10, div)) + '0');
      nbr = nbr % my_power_rec(10, div);
      div--;
      x++;
    }
  if (x == 0)
    ret[x++] = '0';
  ret[x] = 0;
  return (ret);
}

int	create_file_name(char *file_name, int count)
{
  char *m_cp;
  char *nbr;
  int x;

  m_cp = my_strdup(file_name);
  x = 0;
  if (m_cp == NULL || m_cp == NULL)
    return (EXIT_FAILURE);
  while (file_name[x])
    x++;
  file_name[x] = '/';
  file_name[x + 1] = 0;
  file_name = my_strcat(file_name, m_cp);
  nbr = nbr_to_str(count);
  if (nbr != NULL)
    {
      file_name = my_strcat(file_name, "-");
      file_name = my_strcat(file_name, nbr);
      free(nbr);
    }
  file_name = my_strcat(file_name, ".jpg");
  free(m_cp);
  return (EXIT_SUCCESS);
}

int	determ_export(t_global *global, char *dest, int count)
{
  int type;
  char *file_name;

  if (dest == NULL || my_strlen(dest) < 1 || \
			     (file_name = malloc
			      (((my_strlen(dest) * 3)
				+ 10 + nbr_len(count))
			       * sizeof(char))) == NULL)
    return (EXIT_FAILURE);
  type = determ_type_n_file_name(file_name, dest);
  if (type == 0)
    {
      if (count == 0)
	if (mkdir(file_name, S_IRWXU | S_IRUSR | S_IRGRP | S_IROTH) == -1)
	  return (EXIT_FAILURE);
      if (count >= 0)
	create_file_name(file_name, count);
      export_jpg(global, file_name);
    }
  if (type == 1)
    export_bmp(global, my_strcat(file_name, ".bmp"), 0);
  free(file_name);
  return (EXIT_SUCCESS);
}
