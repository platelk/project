/*
** creat_one_instruction.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/data
**
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
**
** Started on  Fri Mar 23 15:16:19 2012 alexandre deceneux
** Last update Fri Mar 23 16:34:34 2012 alexandre deceneux
*/

#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "label.h"
#include "instruction.h"
#include "corewar.h"

/*Find a mnemo id by his name*/
int	get_mnemo_id(char *name)
{
  int   i;

  i = 0;
  if (name != NULL)
    {
      while (i < 16)
	{
	  if (!my_strcmp(op_tab[i].mnemonique, name))
	    return (op_tab[i].code);
	  i++;
	}
    }
  return (-1);
}

/*Return the size of an instruction*/
int	calc_size(char *name, char **arg)
{
  int	size;
  int	id_mnemo;
  int	i;

  size = 1;
  id_mnemo = get_mnemo_id(name);
  if (id_mnemo == -1)
    return (0);
  if (id_mnemo == 9)
    return (3);
  if (id_mnemo != 9 && id_mnemo != 1 && id_mnemo != 15 && id_mnemo != 12)
    size++;
  i = -1;
  if (arg)
    {
      while (arg[++i])
	size += octets_mnemo(arg[i][0], op_tab[id_mnemo - 1].type[i], id_mnemo, i);
    }
  i = -1;
  if (name == NULL && arg)
    while (arg[++i])
      size += my_strlen(arg[i]);
  return (size);
}

t_instruction	*remp_inst(t_instruction *new, int l,
			   t_label *label, char **tab)
{
  new->line = l;
  new->label = label;
  new->name = my_strdup(tab[0]);
  return (new);
}

/*Initialise instruction values*/
void		init_values(t_instruction *new, t_instruction *inst,
			    char **tab, t_label *label)
{
  new->right = NULL;
  if (inst != NULL)
    inst->right = new;
  if (my_strcmp(label->name[0], ".code") == 0)
    new->arg = tab;
  else
    if (tab != NULL && tab[0] != NULL)
      new->arg = get_param(&tab[1], new);
}

/*Create one t_instruction*/
t_instruction	*creat_one_inst(char *s, t_instruction *inst,
				t_label *label, int l)
{
  char	**tab;
  t_instruction	*new;

  tab = my_strtok(s, "/ ,\t\n=*)(|][");
  if ((new = malloc(sizeof(*new))) == 0)
    return (NULL);
  while (inst != NULL && inst->right != NULL)
    inst = inst->right;
  new = remp_inst(new, l, label, tab);
  new->left = inst;
  init_values(new, inst, tab, label);
  if (new->arg == NULL)
    {
      print_error_message("Asm: Bads arguments", *(label->name), *tab, l);
      return (NULL);
    }
  new->size = calc_size(new->name, new->arg);
  my_free_tab(tab);
  return (new);
}
