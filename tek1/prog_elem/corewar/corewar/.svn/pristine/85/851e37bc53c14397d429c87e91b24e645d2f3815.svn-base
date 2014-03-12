/*
** get_comment.c for Corewar in /home/decene_a//afs/Projets/Korewar/Doc/SVN/corewar/data/asm/source/data
** 
** Made by alexandre deceneux
** Login   <decene_a@epitech.net>
** 
** Started on  Thu Mar 22 13:47:43 2012 alexandre deceneux
** Last update Thu Mar 22 13:47:50 2012 alexandre deceneux
*/

#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

#include "corewar.h"
#include "get_next_line.h"

char	*check_comment(int fd, int *l)
{
  char  *tmp;
  char  **tab;
  char  *bdd;

  if ((tmp = jump_comment(fd, l)) == NULL)
    return (NULL);
  bdd = my_strdup(".comment");
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

int	get_comment(int fd, header_t *header, int *l)
{
  char	*tmp;
  int i;
  int k;
  int ret;

  ret = EXIT_SUCCESS;
  i = 0;
  k = -1;
  if ((tmp = check_comment(fd, l)) == NULL)
    {
      my_puterror("Asm: Warning: missing .comment.\n");
      return (EXIT_SUCCESS);
    }
  while (tmp[i] != '"' && tmp[i] != '\0')
    i++;
  while (k < COMMENT_LENGTH && tmp[++i] != '"' && tmp[i] != '\0')
    header->comment[++k] = tmp[i];
  while (k <= (COMMENT_LENGTH))
    header->comment[++k] = '\0';
  if (tmp[i] != '"')
    ret = EXIT_FAILURE;
  free(tmp);
  my_printf("Comment: %s\n", header->comment);
  return (ret);
}
