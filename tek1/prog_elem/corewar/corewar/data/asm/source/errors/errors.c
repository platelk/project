/*
** errors.c for Corewar in /home/decene_a//afs/Projets/Korewar/Code/errors
**
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
**
** Started on  Mon Jan 23 15:19:55 2012 alexandre deceneux
** Last update Sun Mar 25 20:41:08 2012 ronan guiho
*/

#include <stdlib.h>
#include "label.h"
#include "op.h"
#include "my.h"
#include "corewar.h"

/*Print error message*/
void	print_error_message(char *message, char *label, char *mnemo, int l)
{
  my_puterror(message);
  if (mnemo)
    {
      my_putchar(10);
      my_puterror("         At mnemonic : ");
      my_puterror(mnemo);
      my_printf(" at line %d", l);
    }
  my_putchar(10);
  my_puterror("         In label : ");
  my_puterror(label);
  my_puterror("\n");
}

/*Return all the details of the mnemonique*/
op_t	*find_mnemo(char *name)
{
  int	i;

  i = 0;
  while (i < 16)
    {
      if (!my_strcmp(op_tab[i].mnemonique, name))
	return (&op_tab[i]);
      i++;
    }
  return (0);
}

/*Check the type of the argument*/
int	check_arg_type(char *arg, args_type_t t, t_instruction *i,
		       char *mnemo_name)
{
  if ((t & arg[0]) != T_DIR && arg[0] == T_DIR)
    print_error_message("Asm: Warning: Bad argument",
			*(i->label->name), mnemo_name, i->line);
  if ((t & arg[0]) != T_REG && arg[0] == T_REG)
    print_error_message("Asm: Warning: Bad argument",
			*(i->label->name), mnemo_name, i->line);
  if ((t & arg[0]) != T_IND && arg[0] == T_IND)
    print_error_message("Asm: Warning: Bad argument",
			*(i->label->name), mnemo_name, i->line);
  return (0);
}

/*Check the number of arguments of the instruction*/
int	check_argvs(op_t *mnemo, t_instruction *instruction)
{
  int	i;
  int	max;

  max = 0;
  while (instruction && instruction->arg != NULL && instruction->arg[max++]);
  i = -1;
  while (++i < MAX_ARGS_NUMBER && instruction && instruction->arg)
    {
      if (mnemo->nbr_args > i)
	if (instruction->arg[i])
	  check_arg_type(instruction->arg[i], mnemo->type[i],
			 instruction, mnemo->mnemonique);
	else
	  print_error_message("Asm: Warning: Bad argument",
			      *instruction->label->name, mnemo->mnemonique
				, instruction->line);
      else if (i < max - 1)
	{
	  print_error_message("Asm: Trailing garbage",
			      *instruction->label->name, mnemo->mnemonique
			      , instruction->line);
	  return (1);
	}
    }
  return (0);
}

/*Find errors in a .s file*/
int	find_errors(t_label *list)
{
  t_label	*buffer;
  t_instruction	*buff_instruct;
  op_t		*mnemo;

  buffer = list;
  while (buffer)
    {
      buff_instruct = buffer->right;
      while (buff_instruct)
	{
	  mnemo = find_mnemo(buff_instruct->name);
	  if (unknow_mnemo(mnemo, buff_instruct, buffer))
	    return (1);
	  else if (my_strcmp(buff_instruct->name, ".code") &&
		   check_argvs(mnemo, buff_instruct))
	    return (1);
	  buff_instruct = buff_instruct->right;
	}
      buffer = buffer->next;
    }
  return (0);
}
