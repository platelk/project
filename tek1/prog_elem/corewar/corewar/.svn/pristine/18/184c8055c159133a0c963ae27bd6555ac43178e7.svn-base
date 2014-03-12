/*
** decrease_color.c for corewar in /home/leprov_a//depot/corewar/data/vm/source/game
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Sun Mar 25 20:31:02 2012 alexis leprovost
** Last update Sun Mar 25 21:16:22 2012 alexis leprovost
*/

#include	"corewar.h"

int	decrease_color(t_mem *mem)
{
  static	int flag;
  int	i;

  i = -1;
  if (flag)
    {
      while (++i <= (2 * MEM_SIZE))
	{
	  if (mem->color[RED] != 255)
	    if ((mem->color[RED] = (int)((double)mem->color[RED] * 2.0))
		>= 255)
	      mem->color[RED] = 255;
	  if (mem->color[GREEN] != 255)
	    if ((mem->color[GREEN] = (int)((double)mem->color[GREEN] * 2.0))
		>= 255)
	      mem->color[GREEN] = 255;
	  if (mem->color[BLUE] != 255)
	    if ((mem->color[BLUE] = (int)((double)mem->color[BLUE] * 2.0))
		>= 255)
	      mem->color[BLUE] = 255;
	  mem = mem->next;
	}
    }
  flag = !flag;
  return (EXIT_SUCCESS);
}
