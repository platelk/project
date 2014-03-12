/*
** creat_one_label.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/data
**
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
**
** Started on  Thu Mar 22 12:35:09 2012 alexandre deceneux
** Last update Sat Mar 24 13:54:34 2012 alexandre deceneux
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include "my.h"
#include "label.h"
#include "instruction.h"
#include "corewar.h"

int	no_name(int j, char ***name)
{
  if (j == 0)
    return (1);
  if ((*name = malloc((j + 2) * sizeof(**name))) == NULL)
    return (1);
  return (0);
}

char	**get_name_label(char *buffer, int fd)
{
 int		i;
 int		j;
 char		**tab;
 char		**name;

 i = -1;
 j = 0;
 tab = my_strtok(buffer, " :\n\t");
 while (buffer[++i])
   if (buffer[i] == ':' &&
       (buffer[i + 1] == '\n' || buffer[i + 1] == '\t'
	|| buffer[i + 1] == ' ' || buffer[i + 1] == 0))
     j++;
 if (no_name(j, &name))
   return (NULL);
 name[j] = NULL;
 i = j;
 while (--j >= 0)
   name[j] = my_strdup(tab[j]);
 i > 0 ? (i = i - 1) : (i = i);
 if (my_strcmp(".code", tab[0]) == 0)
   name[0] = my_strdup(tab[0]);
 lseek(fd, -(my_strlen(buffer) - (my_strlen(name[i]) + 1)), SEEK_CUR);
 return (name);
}

/*Calcul the size of a label*/
int	get_label_size(t_instruction *list)
{
  int	size;

  size = 0;
  while (list)
    {
      size += list->size;
      list = list->right;
    }
  return (size);
}

/*Initialise label values*/
void	init_label_values(t_label *new, t_label *label, int fd, int *l)
{
  new->prev = label;
  new->next = NULL;
  new->left = NULL;
  if (label != NULL)
    label->next = new;
  new->right = creat_list_instruct(fd, new, l);
  new->size = get_label_size(new->right);
}

/*Create one new label*/
t_label	*creat_one_label(char *buffer, int fd, t_label *label, int *l)
{
  t_label	*new;
  int	i;

  i = -1;
  while (buffer[++i] != ':' && buffer[i] !=0);
  while (buffer[i] != 0 && buffer[++i] != 0
	 && (buffer[i] > 'z' || buffer[i] < 'a'));
  if (buffer[i] >= 'a' && buffer[i] <= 'z')
    *l = *l - 1;
  while (label != NULL && label->next != NULL)
    label = label->next;
  if ((new = malloc(sizeof(*new))) == NULL)
    return (NULL);
  new->line = *l;
  new->name = get_name_label(buffer, fd);
  if (new->name == NULL)
    {
      new->name = malloc(2 * sizeof(char *));
      new->name[0] = my_strdup("<no_label>");
      new->name[1] = NULL;
      lseek(fd, -(my_strlen(buffer)), SEEK_CUR);
    }
  init_label_values(new, label, fd, l);
  return (new);
}
