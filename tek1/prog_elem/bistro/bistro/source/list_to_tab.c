/*
** list_to_tab.c for Bistromathique in /home/przyby_m/projet/bistro/source
** 
** Made by matthieu przybylski
** Login   <przyby_m@epitech.net>
** 
** Started on  Sun Nov  6 14:45:32 2011 matthieu przybylski
** Last update Sun Nov  6 14:45:57 2011 matthieu przybylski
*/

#include <stdlib.h>
#include "list.h"
#include "bistromathique.h"
#include "my.h"

char		*list_to_tab(t_list *temp)
{
  int		i;
  char		*tab;

  while (temp->befo != NULL)
    temp = temp->befo;
  tab = malloc (my_list_size(temp) + 2);
  i = 0;
  while (temp != NULL)
    {
      tab[i] = temp->cha;
      temp = temp->next;
      i = i + 1;
    }
  tab[i] = '\n';
  tab[i + 1] = '\0';
  return (tab);
}
