/*
** main.c for Corewar in /home/guiho_r//tek1/corewar/source/VM
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Fri Jan 27 13:19:39 2012 ronan guiho
** Last update Tue Apr  3 13:24:14 2012 alexis leprovost
*/

#include <stdlib.h>
#include <time.h>

#include "corewar.h"
#include "data_champ.h"

int		main(int ac, char **av, char *envp[])
{
  t_vm	*vm;
  func	*instruct;

  if (ac == 1)
    return (my_printf("Usage: ./corewar[option] [option]champ.cor ...\n"));
  srand(time(NULL));
  if ((vm = create_struct_vm(ac, av)) != NULL)
    {
      instruct = get_ptr_func();
      if (envp[0] != NULL)
	{
	  if ((vm->image = init_image()) == NULL)
	    return (my_printf(
		   "Corewar: error: initialization pictures failed.\n"));
	  if ((vm->sound = init_sound()) == NULL)
	    return (my_printf(
		   "Corewar: error: initialization sounds failed.\n"));
	}
      vm->no_graph = rendering(vm);
      battle_ground(vm, instruct);
      if (vm->winner != NULL)
	return (my_printf("Le joueur %s(%d) a gagné.\n", vm->winner->prog_name,
			  vm->winner->data[ID]));
    }
  return (EXIT_SUCCESS);
}
