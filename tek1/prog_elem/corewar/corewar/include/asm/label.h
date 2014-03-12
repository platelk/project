/*
** label.h for label.h in /home/platel_k/projet/prog_elem/corewar/local/include
**
** Made by kevin platel
** Login   <platel_k@epitech.net>
**
** Started on  Sun Jan 22 13:31:48 2012 kevin platel
** Last update Tue Mar 13 10:46:32 2012 kevin platel
*/

#ifndef __LABEL_H_
#define __LABEL_H_

#include "instruction.h"

typedef struct s_label
{
  char **name;
  int  size;
  int line;
  struct s_label *next;
  struct s_label *prev;
  struct s_instruction *left;
  struct s_instruction *right;
} t_label;

#endif
