/*
** ptr_func.h for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Tue Mar 13 14:59:27 2012 alexandre deceneux
** Last update Sun Mar 25 16:34:03 2012 alexandre deceneux
** Last update Wed Mar 14 12:58:16 2012 alexandre deceneux
*/

#ifndef __PTR_FUNC_H__
#define __PTR_FUNC_H__

#include "mem.h"
#include "champ.h"
#include "vm.h"

typedef union s_to_int
{
  int   value;
  char  param[4];
} to_int;

typedef void (*func)(char **,t_champ *, t_vm *, int);

int     get_addr(to_int *convert, char *param);
int     get_param_value(to_int *convert, char *param, t_champ *champ);
int     color_mem_case(t_champ *champ, t_mem *mem, char *param);
void    modif_mem_case(t_champ *champ, t_mem *mem, char *value, int addr);
int     if_pc_in_case(char **params, t_champ *champ, int addr);
int     get_mem_case(t_champ *champ, t_mem *mem, int addr, int size);
void    assign_colors(int *color, int *value);
func    *get_ptr_func();

#endif
