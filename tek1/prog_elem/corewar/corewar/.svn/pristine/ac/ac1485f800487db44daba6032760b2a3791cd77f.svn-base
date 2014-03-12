/*
** calcul_label2.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/data
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Wed Mar 21 15:41:38 2012 alexandre deceneux
** Last update Wed Mar 21 15:41:40 2012 alexandre deceneux
*/

#include <stdlib.h>

#include "corewar.h"

/*Return 1 if the char is a stop-condition*/
int     is_stop_condition(char c)
{
  if (c == '+' || c == '-' || !c || c == 10)
    return (1);
  return (0);
}

/*Check if label's name contain only authorized chars*/
int     check_label_chars(char *name)
{
  int   i;
  int   i2;
  char  *list_auto;

  list_auto = my_strdup(LABEL_CHARS);
  i = 0;
  while (name && name[i])
    {
      i2 = 0;
      while (list_auto[i2] && name[i] != list_auto[i2])
        i2++;
      if (!list_auto[i2])
        {
          if (list_auto)
            free(list_auto);
          return (1);
        }
      i++;
    }
  if (list_auto)
    free(list_auto);
  return (0);
}

int     verif_next(char *name, t_label *list)
{
  int   i;

  while (list)
    {
      i = -1;
      while (list->name[++i])
	if (!my_strcmp(list->name[i], name))
	  return (1);
      list = list->next;
    }
  return (0);
}

/*Check if the name is a correct label name*/
int     check_label_name(char *name, t_label *list)
{
  int   i;

  if (check_label_chars(name))
    {
      print_error_message("Asm: Invalid label character",
                          name, 0, list->line);
      return (1);
    }
  if (verif_next(name, list))
    return (1);
  while (list)
    {
      i = -1;
      while (list->name[++i])
	{
          if (!my_strcmp(list->name[i], name))
            return (1);
        }
      list = list->prev;
    }
  return (0);
}

