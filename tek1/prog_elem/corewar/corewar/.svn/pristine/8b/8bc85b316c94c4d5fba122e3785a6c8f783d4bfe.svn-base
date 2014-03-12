/*
** creat_list_instruct.c for creat_list_instruct.c in /home/platel_k/projet/prog_elem/corewar/corewar/source/ASM/data
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Mon Jan 23 15:44:06 2012 kevin platel
** Last update Fri Mar 23 17:10:12 2012 alexandre deceneux
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "label.h"
#include "instruction.h"
#include "corewar.h"

/*
** check if line content a label
** return EXIT_FAILURE if have label in line
*/

int	is_not_label(char *str, int fd)
{
  int	i;

  i = 0;
  while (str[i])
    {
      if ((str[i] == LABEL_CHAR &&
	  (str[i + 1] == ' ' || str[i + 1] == '\t'
	   || str[i + 1] == '\n' || str[i + 1] == 0))
	  || my_strcmp(str, ".code") == 0)
	{
	  if (my_strcmp(str, ":"))
	    lseek(fd, -(my_strlen(str) + 1), SEEK_CUR);
	  return (EXIT_FAILURE);
	}
      i++;
    }
  return (EXIT_SUCCESS);
}

t_instruction	*creat_list_instruct(int fd, t_label *label, int *l)
{
  t_instruction *instruction;
  int	i;
  char		*buffer;

  instruction = NULL;
  while ((buffer = get_next_line(fd, l)) != NULL
	 && is_not_label(buffer, fd) != EXIT_FAILURE)
    {
      i = 0;
      while (buffer != NULL && (buffer[i] == '\t' || buffer[i] == ' '))
	i++;
      if (buffer != NULL && buffer[i] != 0 &&
	  buffer[i] != '#' && buffer[i] != ';')
	instruction = creat_one_inst(&buffer[i], instruction, label, *l);
      if (instruction == NULL)
	return (NULL);
      free(buffer);
    }
  while (instruction != NULL && instruction->left != NULL)
    instruction = instruction->left;
  return (instruction);
}
