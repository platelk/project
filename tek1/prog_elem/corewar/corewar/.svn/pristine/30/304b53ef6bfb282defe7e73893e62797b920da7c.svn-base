/*
** main.c for corewar_asm in /home/platel_k/projet/prog_elem/corewar/local/source/ASM
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jan 22 13:25:45 2012 kevin platel
** Last update Wed Mar 21 15:07:59 2012 alexis leprovost
*/

#include "corewar.h"

int	main(int ac, char **av)
{
  if (ac == 1)
    my_printf("Usage: ./asm file.s ...\n");
  else
    {
      while ((--ac + 1) > 1)
	{
	  if (!check_file(av[ac]))
	    {
	      my_printf("\033[7;36m#Assembling %s started...\n\033[0m",
			av[ac]);
	      if (!asm_treatment(av[ac]))
		my_printf("\033[1;36m#Assembling completed.\n\033[0m");
	      else
		my_printf("\033[1;31m#Assembling fail.\n\033[0m");
	    }
	  else
	    my_printf("\033[7;31mAsm: File %s isn't a valid type.\n\033[0m",
		      av[ac]);
	}
    }
  return (EXIT_SUCCESS);
}
