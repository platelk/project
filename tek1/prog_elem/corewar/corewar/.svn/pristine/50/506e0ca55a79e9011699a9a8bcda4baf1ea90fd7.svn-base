/*
** get_name.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/data
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Thu Mar 22 13:48:08 2012 alexandre deceneux
** Last update Thu Mar 22 13:48:15 2012 alexandre deceneux
*/

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

#include "corewar.h"
#include "get_next_line.h"
#include "op.h"

char	*check_name(int fd, int *l)
{
  char	*tmp;
  char	**tab;
  char	*bdd;

  if ((tmp = jump_comment(fd, l)) == NULL)
    return (NULL);
  bdd = my_strdup(".name");
  tab = my_str_to_tab(tmp, bdd);
  if (tab == NULL || my_strcmp(tab[0], bdd))
    {
      my_free_tab(tab);
      free(bdd);
      lseek(fd, ((my_strlen(tmp) + 1) * (-1)), SEEK_CUR);
      *l = *l - 1;
      return (NULL);
    }
  my_free_tab(tab);
  free(bdd);
  return (tmp);
}

int	get_name(int fd, header_t *header, int *l)
{
  char	*tmp;
  int	i;
  int	k;
  int	ret;

  ret = EXIT_SUCCESS;
  i = 0;
  k = -1;
  if ((tmp = check_name(fd, l)) == NULL)
    return (EXIT_FAILURE);
  while (tmp[i] != '"' && tmp[i] != '\0')
    i++;
  while (k < (PROG_NAME_LENGTH) && tmp[++i] != '"' && tmp[i] != '\0')
    header->prog_name[++k] = tmp[i];
  while (k <= (PROG_NAME_LENGTH))
    header->prog_name[++k] = '\0';
  if (tmp[i] != '"')
    ret = EXIT_FAILURE;
  free(tmp);
  if (!ret)
    my_printf("Name: %s\n", header->prog_name);
  return (ret);
}
