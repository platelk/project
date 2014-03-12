/*
** check_champ.c for Corewar in /home/leprov_a//depot/corewar/source/VM/check
** 
** Made by alexis leprovost
** Login   <leprov_a@epitech.net>
** 
** Started on  Thu Feb  9 15:51:01 2012 alexis leprovost
** Last update Fri Mar 23 09:21:05 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"

int	*get_color(int nb)
{
  int	*color;

  if ((color = malloc(sizeof(*color) * 3)) == NULL)
    return (NULL);
  color[RED] = (nb >> 16) % 256;
  color[GREEN] = (nb >> 8) % 256;
  color[BLUE] = nb % 256;
  if (!color[RED])
    color[RED] = 1;
  if (!color[GREEN])
    color[GREEN] = 1;
  if (!color[BLUE])
    color[BLUE] = 1;
  return (color);
}

int	check_champ(t_champ *champ, t_param *param)
{
  t_champ	*tmp;
  int	color;
  int	nb;

  nb = get_champ_number(champ);
  color = 255;
  tmp = champ;
  while (tmp != NULL)
    {
      if (get_id_available(tmp) == -1 ||
	  get_addr_available(tmp, nb) == -1 ||
	  (tmp->color = get_color(color)) == NULL ||
	  (tmp->reg = dump_reg(param, tmp->data[ID])) == NULL)
	return (-1);
      color = color << 8;
      tmp = tmp->next;
    }
  return (0);
}
