/*
** create_mem.c for Corewar in /home/guiho_r/tek1/corewar/include/vm
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Mar 18 23:06:45 2012 ronan guiho
** Last update Sat Mar 24 09:37:05 2012 ronan guiho
*/

#include <math.h>
#include <stdlib.h>

#include "vm.h"
#include "corewar.h"

void	fill_rect_mem(t_mem *tmp, int x, int y, int step)
{
  tmp->p.x = x;
  tmp->p.y = y;
  tmp->p.w = step;
  tmp->p.h = step;
}

int	create_disp_mem(t_vm *vm)
{
  int	i;
  int	x;
  int	y;
  t_mem	*tmp;
  int   step;

  i = 0;
  y = 0;
  tmp = vm->mem;
  step = (int)sqrt(((WIDTH_MEM * HEIGHT_MEM) / MEM_SIZE));
  while (y <=  HEIGHT_MEM)
    {
      x = 0;
      while (x < WIDTH_MEM)
	{
	  fill_rect_mem(tmp, x, y, step);
	  x = x + step;
	  tmp = tmp->next;
	  i++;
	  if (i == MEM_SIZE)
	    return (EXIT_SUCCESS);
	}
      y = y + step;
    }
  return (EXIT_SUCCESS);
}
