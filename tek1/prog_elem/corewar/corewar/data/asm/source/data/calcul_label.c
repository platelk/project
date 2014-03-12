/*
** calcul_label.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/source/ASM/data
**
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
**
** Started on  Mon Jan 30 14:14:52 2012 alexandre deceneux
** Last update Wed Mar 21 15:01:29 2012 alexis leprovost
*/

#include <stdlib.h>

#include "corewar.h"

/* Add one char to the char* */
char	*add_one(char *str, char c)
{
  char	*ret;
  int	i;

  ret = malloc(sizeof(*ret) * (my_strlen(str) + 2));
  if (ret == NULL)
    return (str);
  i = 0;
  while (str && str[i])
    {
      ret[i] = str[i];
      i++;
    }
  ret[i] = c;
  ret[i + 1] = 0;
  if (str)
    free(str);
  return (ret);
}

/*Calcul a part of the label*/
int	calcul_part(char *buffer, int lab, t_label *list,
		    t_instruction *inst)
{
  int	dir;

  if (lab)
    {
      dir = get_direction_search(buffer + 1, inst);
      if (buffer != NULL && check_label_name(buffer + 1, list))
	return (calc_dist(dir, inst, inst->label, buffer + 1) * dir);
      else
	print_error_message("Asm: Label not defined",
			    *inst->label->name, inst->name, inst->line);
      return (-1);
    }
  if (buffer != NULL && !my_str_isnum(buffer))
    {
      print_error_message("Asm: Trailing garbage",
			  *(inst->label->name), inst->name, inst->line);
      return (-1);
    }
  return (my_getnbr(buffer));
}

void	init_start_var(char **buffer, int *i, int *is_label, int *ret)
{
  *ret = 0;
  *i = 0;
  *is_label = 0;
  *buffer = 0;
}

/*Calcul the label*/
char	*calcul_label(char *s, t_label *list, t_instruction *inst, char *p)
{
  char	*buffer;
  int	i;
  int	is_label;
  int	ret;

  init_start_var(&buffer, &i, &is_label, &ret);
  while (s[i])
    {
      if (s[i] == ':')
	is_label = 1;
      if (is_stop_condition(s[i]) || !s[i + 1])
	{
	  if (!s[i + 1])
	    buffer = add_one(buffer, s[i]);
	  ret += calcul_part(buffer, is_label, list, inst);
	  is_label = 0;
	  if (buffer)
	    free(buffer);
	  buffer = NULL;
	}
      else if (s[i] != '%')
	buffer = add_one(buffer, s[i]);
      i++;
    }
  return (write_int_in_str(ret, p));
}
