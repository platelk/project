/*
** add_champ.c for add_champ in /home/leprov_a//depot/corewar/data/vm/source/struct
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Fri Mar 23 11:45:31 2012 alexis leprovost
** Last update Fri Mar 23 12:05:30 2012 alexis leprovost
*/

#include	<stdlib.h>

#include	"corewar.h"

int	*cp_reg(int *old_reg)
{
  int   i;
  int   *new_reg;

  i = 0;
  if ((new_reg = malloc(sizeof(int) * REG_NUMBER)) == NULL)
    return (NULL);
  new_reg[i] = old_reg[i];
  while (++i < REG_NUMBER)
    new_reg[i] = old_reg[i];
  return (new_reg);
}

int	*cp_data(int *old_data, int pc)
{
  int   *new_data;

  if ((new_data = malloc(sizeof(int) * (SIZE_DATA + 1))) == NULL)
    return (NULL);
  new_data[ADDR] = old_data[ADDR];
  new_data[ID] = old_data[ID];
  new_data[CARRY] = old_data[CARRY];
  new_data[PC] = pc;
  new_data[LIVE] = old_data[LIVE];
  return (new_data);
}

void	cp_champ(t_champ *new, t_champ *old, int pc)
{
  new->instruct = old->instruct;
  new->cycle_instruct = old->cycle_instruct;
  new->prog_name = my_strdup(old->prog_name);
  new->detail = NULL;
  new->bin = NULL;
  new->reg = cp_reg(old->reg);
  new->data = cp_data(old->data, pc);
  new->prog_size = old->prog_size;
  new->color = get_color(0x000000);
  new->color[RED] = old->color[RED];
  new->color[GREEN] = old->color[GREEN];
  new->color[BLUE] = old->color[BLUE];
}

t_champ	*add_champ(t_champ *champ, int pc)
{
  t_champ	*new_element;

  if ((new_element = malloc(sizeof(*new_element))) == NULL)
    exit(EXIT_FAILURE);
  new_element->next = NULL;
  new_element->before = NULL;
  cp_champ(new_element, champ, pc);
  return (new_element);
}
