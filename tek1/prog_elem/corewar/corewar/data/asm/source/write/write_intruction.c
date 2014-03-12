/*
** write_intruction.c for write_instruction in /home/platel_k/projet/prog_elem/corewar/corewar
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Wed Jan 25 13:17:49 2012 kevin platel
** Last update Tue Feb  7 17:12:39 2012 alexis leprovost
*/

#include <stdlib.h>
#include <unistd.h>

#include "corewar.h"
#include "label.h"

int		write_code(t_instruction *instruct, int fd)
{
  int	i;
  char	value;

  i = -1;
  while (instruct->arg[++i])
    {
      value = my_getnbr(instruct->arg[i]);
      write(fd, &value, my_strlen(instruct->arg[i]));
    }
  return (i);
}

t_instruction   *write_free_inst(t_instruction *instruct, int fd)
{
  t_instruction	*tmp;
  char		id_name;

  id_name = get_hex_instruct(fd, instruct);
  write_argument(fd, instruct, id_name);
  if (instruct->name != NULL)
    free(instruct->name);
  if (instruct->arg != NULL)
    my_free_tab(instruct->arg);
  tmp = instruct;
  instruct = instruct->right;
  if (tmp != NULL)
    free(tmp);
  return (instruct);
}

int		write_instruction(int fd, t_label *list)
{
  t_label	*tmp;
  t_label	*label;
  t_instruction *instruct;

  label = list;
  while (label)
    {
      instruct = label->right;
      if (my_strcmp(label->name[0], ".code") == 0)
	write_code(instruct, fd);
      else
	while (instruct)
	  instruct = write_free_inst(instruct, fd);
      tmp = label;
      my_free_tab(label->name);
      label = label->next;
      if (tmp != NULL)
	free(tmp);
    }
  close(fd);
  return (0);
}
