/*
** assign_colors.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/vm/source/struct
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Sun Mar 25 16:32:43 2012 alexandre deceneux
** Last update Sun Mar 25 16:33:49 2012 alexandre deceneux
*/

#include "corewar.h"

void	assign_colors(int *color, int *value)
{
  color[RED] = value[RED];
  color[BLUE] = value[BLUE];
  color[GREEN] = value[GREEN];
}
