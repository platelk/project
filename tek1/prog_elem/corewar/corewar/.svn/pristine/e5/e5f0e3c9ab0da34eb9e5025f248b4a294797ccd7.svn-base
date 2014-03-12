/*
** get_list_label.c for get_list_label in /home/platel_k/projet/prog_elem/corewar/local/source/ASM/get_data
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jan 22 13:29:22 2012 kevin platel
** Last update Fri Mar 23 16:41:58 2012 alexandre deceneux
*/

#include "my.h"
#include "label.h"
#include "instruction.h"
#include "corewar.h"

t_label	*get_list_label(int fd, int *l)
{
  t_label	*label;

  label = creat_list_label(fd, l);
  if (!label)
    my_printf("Corewar: Error: No Label\n");
  return (label);
}
