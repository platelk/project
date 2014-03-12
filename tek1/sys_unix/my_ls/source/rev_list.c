/*
** rev_list.c for rev_list in /home/platel_k/projet/my_ls/source
** 
** Made by kevin platel
** Login   <platel_k@epitech.net>
** 
** Started on  Tue Nov 29 13:58:08 2011 kevin platel
** Last update Wed Nov 30 19:23:28 2011 kevin platel
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <stdlib.h>
#include <unistd.h>
#include "data.h"
#include "my.h"
#include "my_ls.h"

void	rev(t_data **begin)
{
  t_data	*tmp;

  tmp = (*begin)->next;
  (*begin)->next = (*begin)->prev;
  (*begin)->prev = tmp;
}

void	rev_list(t_data **directory)
{
  t_data	*tmp;
  t_data	*begin;

  begin = (*directory);
  while (begin != NULL)
    {
      tmp = begin;
      begin = begin->next;
      rev(&tmp);
    }
  (*directory) = tmp;
}
