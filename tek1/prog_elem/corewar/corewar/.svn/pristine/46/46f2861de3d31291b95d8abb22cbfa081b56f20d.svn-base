/*
** dump_mem.c for vm in /home/platel_k/projet/prog_elem/corewar/corewar/data/vm/source/game
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Fri Mar 23 14:31:56 2012 kevin platel
** Last update Sun Mar 25 01:51:14 2012 ronan guiho
*/

#include	<stdlib.h>

#include	"corewar.h"
#include	"op.h"

t_mem	*go_to_start(t_mem *mem)
{
  int	lin;

  lin = 0;
  my_printf("\n       %x%x", lin, lin);
  while (++lin < 16)
    my_printf(" %x%x", lin, lin);
  my_printf("\n");
  while (mem->indice != 0)
    mem = mem->next;
  return (mem);
}

int	mem_dump(t_mem *mem)
{
  int	col;
  int	lin;
  int	i;

  i = 0;
  mem = go_to_start(mem);
  lin = 0;
  while (i < MEM_SIZE)
    {
      col = -1;
      my_printf("%2.x0 : ", lin);
      while (++col < 16 && i < MEM_SIZE)
	{
	  my_printf("%1.x ", (unsigned char) mem->value);
	  mem = mem->next;
	  i++;
	}
      my_printf("\n");
      lin++;
    }
  return (0);
}
