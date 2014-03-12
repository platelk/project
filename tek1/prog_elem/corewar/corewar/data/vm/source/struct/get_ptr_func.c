/*
** get_ptr_func.c for Asm in /home/guiho_r/tek1/corewar/data/vm/source/game
** 
** Made by ronan guiho
** Login   <guiho_r@epitech.net>
** 
** Started on  Sun Mar 25 03:11:43 2012 ronan guiho
** Last update Tue Apr  3 15:00:16 2012 kevin platel
*/

#include "corewar.h"

int	*getcolor_following_idchamp(t_champ *champ)
{
  int	*color;
  t_champ	*tmp;

  tmp = champ;
  while (tmp != NULL && tmp->before != NULL)
    tmp = tmp->before;
  color = get_color(0x000000);
  while (tmp != NULL && tmp->data[ID] != champ->reg[0])
    tmp = tmp->next;
  if (tmp == NULL)
    {
      color[RED] = 90;
      color[GREEN] = 90;
      color[BLUE] = 90;
    }
  else
    {
      color[RED] = tmp->color[RED];
      color[GREEN] = tmp->color[GREEN];
      color[BLUE] = tmp->color[BLUE];
    }
  return (color);
}

void	modif_mem_case(t_champ *champ, t_mem *mem, char *value, int addr)
{
  int	i;
  int	*color;

  color = getcolor_following_idchamp(champ);
  if (((mem->indice - (addr)) % MEM_SIZE) < 0)
    while (mem->next->indice != (addr % MEM_SIZE))
      mem = mem->next;
  else
    while (mem->next->indice != (addr % MEM_SIZE))
      mem = mem->before;
  i = -1;
  while (++i < 4)
    {
      if (value[i])
	mem->value = value[i];
      mem->state = WRITE;
      assign_colors(mem->color, color);
      mem = mem->before;
    }
  mem->state = WRITE;
  assign_colors(mem->color, color);
  free(color);
}

int	get_mem_case(t_champ *champ, t_mem *mem, int addr, int size)
{
  int		i;
  int	*color;
  to_int	convert;

  color = getcolor_following_idchamp(champ);
  if (((mem->indice - (addr)) % MEM_SIZE) < 0)
    while (mem->next->indice != (addr % MEM_SIZE))
      mem = mem->next;
  else
    while (mem->next->indice != (addr % MEM_SIZE))
      mem = mem->before;
  i = -1;
  while (++i < size)
    {
      convert.param[3 - i] = mem->value;
      mem->state = READ;
      assign_colors(mem->color, color);
      mem = mem->before;
    }
  --i;
  while (++i < 4)
    convert.param[3 - i] = 0;
  assign_colors(mem->color, color);
  mem->state = READ;
  return (convert.value);
}

int     color_mem_case(t_champ *champ, t_mem *mem, char *param)
{
  int           i;
  int	*color;

  color = getcolor_following_idchamp(champ);
  i = -1;
  if ((mem->indice - ((champ->data[ADDR] + champ->data[PC]))) % MEM_SIZE < 0)
    while (mem->indice != ((champ->data[ADDR] + champ->data[PC]) % MEM_SIZE))
      mem = mem->next;
  else
    while (mem->indice != ((champ->data[ADDR] + champ->data[PC]) % MEM_SIZE))
      mem = mem->before;
  while (++i < param[1])
    {
      mem->state = param[0];
      mem->color[RED] = color[RED];
      mem->color[GREEN] = color[GREEN];
      mem->color[BLUE] = color[BLUE];
      mem = mem->next;
    }
  free(color);
  return (EXIT_FAILURE);
}

func    *get_ptr_func()
{
  func  *functs;

  functs = malloc(sizeof(*functs) * 17);
  functs[0] = &live;
  functs[1] = &ld;
  functs[2] = &st;
  functs[3] = &add;
  functs[4] = &sub;
  functs[5] = &and;
  functs[6] = &or;
  functs[7] = &xor;
  functs[8] = &zjmp;
  functs[9] = &ldi;
  functs[10] = &sti;
  functs[11] = &ifork;
  functs[12] = &lld;
  functs[13] = &lldi;
  functs[14] = &lfork;
  functs[15] = &aff;
  functs[16] = 0;
  return (functs);
}
