/*
** check.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/write
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Fri Mar 23 15:17:01 2012 alexandre deceneux
** Last update Fri Mar 23 15:21:14 2012 alexandre deceneux
*/

#include <stdlib.h>
#include "my.h"
#include "op.h"

/*Return the number of octet that take the argument*/
int	octets_from_type(char type)
{
  if (type & T_LAB)
    return (IND_SIZE);
  else if ((type & T_IND) == T_IND)
    return (IND_SIZE);
  else if (type & T_DIR)
    return (DIR_SIZE);
  else if ((type & T_REG) == T_REG)
    return ((REG_NUMBER - 1) / 255 + 1);
  return (0);
}

int	octets_mnemo(int type, char arg_get, int id, int pos)
{
  int	without_lab;

  without_lab = type & ~T_LAB;
  if ((arg_get & without_lab) != 0)
    {
      if (id == 9 || id == 12)
	return (IND_SIZE);
      else if (id == 10 && (pos == 1 || !pos) &&
	       (arg_get & without_lab) == T_DIR)
	return (IND_SIZE);
      else if ((arg_get & without_lab) == T_DIR && id == 11 && pos)
	return (IND_SIZE);
      else if ((arg_get & without_lab) == T_DIR && id == 14 && pos == 1)
	return (IND_SIZE);
      return (octets_from_type(without_lab));
    }
  else if (id == 12)
    return (IND_SIZE);
  else if ((type & T_LAB) && (arg_get & T_IND))
    return (IND_SIZE);
  else
    return (octets_from_type(type));
}

/*Fill the value to return*/
char	*fill_to_write(char *to_write, char *name, int nbr_octets)
{
  int	i;
  int	j;

  i = nbr_octets - 1;
  j = (octets_from_type(name[0]));
  while (i >= 0 && j > 0)
    {
      to_write[i] = name[j];
      i--;
      j--;
    }
  return (to_write);
}

/*Return the char* in hexa, to write in the file*/
char	*cast_param(char id_mnemo, char *name, int pos, int *len)
{
  int	i;
  int	nbr_octets;
  char	*to_write;

  i = 0;
  while ((op_tab[i].mnemonique) && op_tab[i].code != id_mnemo)
    i++;
  if (!op_tab[i].mnemonique)
    return (NULL);
  if (pos >= op_tab[i].nbr_args)
    return (NULL);
  nbr_octets = octets_mnemo(name[0], op_tab[i].type[pos], id_mnemo, pos);
  if (nbr_octets == 0)
    return (NULL);
  to_write = malloc(sizeof(*to_write) * (nbr_octets));
  if (to_write == NULL)
    return (NULL);
  *len = nbr_octets;
  to_write = fill_to_write(to_write, name, nbr_octets);
  return (to_write);
}
