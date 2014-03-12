/*
** battle_ground.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/vm/source/game
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Sun Mar 25 17:21:12 2012 alexandre deceneux
** Last update Tue Apr  3 15:25:35 2012 kevin platel
*/

#include	<stdlib.h>

#include	"corewar.h"
#include	"op.h"

void		key_battel_ground(t_vm *vm)
{
  SDL_Event	event;
  static int	flag;

  while (SDL_PollEvent(&event))
    {
      if (event.type == SDL_QUIT)
	exit (1);
      if (event.key.keysym.sym == SDLK_ESCAPE)
	exit (1);
      if (event.key.keysym.sym == SDLK_p)
	{
	  if (flag == 0)
	    vm->no_graph = 0;
	  else
	    vm->no_graph = 1;
	  flag = (flag == 0) ? 1 : 0;
	}
    }
}

int	get_nbr_champ(t_champ *champ)
{
  t_champ       *tmp;
  int		nb_champ;

  tmp = champ;
  nb_champ = 0;
  while (tmp != NULL)
    {
      nb_champ++;
      tmp = tmp->next;
    }
  return (nb_champ);
}

int	battle_ground(t_vm *vm, func *instruct)
{
  int	i;
  int	end_game;

  end_game = CYCLE_TO_DIE;
  vm->cycle_to_die = end_game;
  while (end_game > 0)
    {
      i = -1;
      while (++i < end_game)
	{
	  engine(vm, instruct);
	  if (vm->param->nbr_live > 0)
	    --vm->param->nbr_live;
	  --vm->param->dump;
	  if (!vm->param->dump)
	    return (mem_dump(vm->mem));
	}
      /*if (clean_game(vm->champ) >= (vm->nb_champ - 1) || display_msg(vm) > -5 || vm->nb_champ <= 1)
	end_game = -42;*/
      end_game -= CYCLE_DELTA;
      vm->cycle_to_die = end_game;
    }
  display_msg(vm);
  free_vm(vm);
  return (EXIT_SUCCESS);
}
