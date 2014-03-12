/*
** get_addr_label.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/source/ASM/data
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Wed Feb 15 18:47:23 2012 alexandre deceneux
** Last update Thu Feb 16 20:17:39 2012 kevin platel
*/

#include <stdlib.h>
#include "corewar.h"

int	find_in_next(t_label *search, char *line, t_instruction *instruct)
{
  int	i;
  int	size;

  size = 0;
  while (instruct != NULL)
    {
      size += instruct->size;
      instruct = instruct->right;
    }
  if (search != NULL)
    search = search->next;
  while (search != NULL)
    {
      i = -1;
      while (search->name[++i] != NULL)
	if (my_strcmp(line, search->name[i]) == 0)
	  return (size);
      size += search->size;
      search = search->next;
    }
  return (size);
}

int	find_in_prev(t_label *search, char *line, t_instruction *instruct)
{
  int	i;
  int	size;

  size = 0;
  while ((instruct = instruct->left) != NULL)
    if (instruct != NULL)
      size += instruct->size;
  i = -1;
  while (search->name[++i])
    if (my_strcmp(line, search->name[i]) == 0)
      return (size);
  if (search != NULL)
    search = search->prev;
  while (search != NULL)
    {
      i = -1;
      size += search->size;
      while (search->name[++i] != NULL)
	if (my_strcmp(line, search->name[i]) == 0)
	  return (size);
      search = search->prev;
    }
  return (size);
}

int	calc_dist(int dir, t_instruction *instruct, t_label *label, char *line)
{
  int	size;

  if (instruct != NULL)
    {
      if (dir < 0)
	size = find_in_prev(label, line, instruct);
      else if (dir > 0)
	size = find_in_next(label, line, instruct);
    }
  return (size);
}

char	*get_addr_label(t_instruction *instruct, char *line, char *param)
{
  int	size;
  int	dir;
  char	**str;

  str = my_strtok(line, " \n:%,\t");
  if (str != NULL)
    dir = get_direction_search(str[0], instruct);
  my_printf("dir = %d && name = %s\n", dir, instruct->name);
  if (instruct != NULL)
    {
      size = calc_dist(dir, instruct, instruct->label, str[0]);
      size = size * dir;
      param = write_int_in_str(size, param);
    }
  return (param);
}
