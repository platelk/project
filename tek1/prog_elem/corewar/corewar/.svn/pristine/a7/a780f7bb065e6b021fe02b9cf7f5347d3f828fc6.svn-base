/*
** check_mnemo.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/errors
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Fri Mar 23 16:57:47 2012 alexandre deceneux
** Last update Sun Mar 25 01:54:41 2012 ronan guiho
*/

#include "corewar.h"

/*Return 1 if is an unknow mnemonique*/
int     unknow_mnemo(op_t *mnemo, t_instruction *buff_instruct,
                     t_label *buffer)
{
  if (!mnemo && my_strcmp(buff_instruct->name, ".code"))
    {
      print_error_message("Asm: Unknow mnemonique",
                          *buffer->name, buff_instruct->name
                          , buff_instruct->line);
      return (1);
    }
  return (0);
}
